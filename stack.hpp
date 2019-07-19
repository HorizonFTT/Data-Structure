template <typename T>
class Stack {
    static const int MAXSIZE = 50;

private:
    T data[MAXSIZE];
    int top = -1;

public:
    void initStack() { top = -1; }

    bool stackEmpty() { return top == -1 ? true : false; }

    bool push(T elem) {
        if (top == MAXSIZE - 1) {
            return false;
        }
        data[++top] = elem;
        return true;
    }

    bool pop(T &elem) {
        if (top == -1) {
            return false;
        }
        elem = data[top--];
        return true;
    }

    bool getTop(T &elem) {
        if (top == -1) {
            return false;
        }
        elem = data[top];
        return true;
    }
};
