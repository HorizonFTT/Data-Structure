template <typename T>
class Queue {
    static const int MAXSIZE = 50;

private:
    T data[MAXSIZE];
    int front = 0;
    int rear = 0;

public:
    void initQueue() { front = rear = 0; }

    bool queueEmpty() { return rear == front ? true : false; }

    bool enQueue(T elem) {
        if ((rear + 1) % MAXSIZE == front) {
            return false;
        }
        data[rear] = elem;
        rear = (rear + 1) % MAXSIZE;
        return true;
    }

    bool deQueue(T &elem) {
        if (rear == front) {
            return false;
        }
        elem = data[front];
        front = (front + 1) % MAXSIZE;
        return true;
    }

    bool getHead(T &elem) {
        if (rear == front) {
            return false;
        }
        elem = data[front];
        return true;
    }
};
