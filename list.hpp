#include <iostream>

class Algorithm;

template <typename T>
class List;

template <typename T>
class ListNode {
    friend class List<T>;
    friend class Algorithm;

private:
    T data;
    ListNode<T>* next;

public:
    ListNode(T data) : data(data), next(nullptr) {}
};

template <typename T>
class List {
    friend class Algorithm;

private:
    ListNode<T>* head;

public:
    static List<T>* createList(size_t n = 0) {
        T data;
        List<T>* l = new List();
        if (n == 0) {
            std::cin >> n;
        }
        while (n != 0) {
            std::cin >> data;
            l->listInsert(data);
            --n;
        }
        return l;
    }

    List() : head(new ListNode<T>(-1)){};

    size_t length() {
        ListNode<T>* temp = head->next;
        size_t count = 0;
        while (temp != nullptr) {
            ++count;
            temp = temp->next;
        }
        return count;         
    }

    ListNode<T>* locateElem(T elem) {
        ListNode<T>* temp = head->next;
        while (temp != nullptr) {
            if (temp->data == elem) {
                break;
            }
            temp = temp->next;
        }
        return temp;
    }

    T getElem(size_t index) {
        ListNode<T>* temp = head->next;
        while (temp != nullptr) {
            if (index == 0) {
                break;
            }
            --index;
            temp = temp->next;
        }
        return temp->data;
    }

    void listInsert(T elem, size_t index = 0) {
        ListNode<T>* temp = head;
        ListNode<T>* node = new ListNode<T>(elem);
        do {
            if (index == 0) {
                node->next = temp->next;
                temp->next = node;
                break;
            }
            --index;
            temp = temp->next;
        } while (temp != nullptr);
    }

    T listDelete(size_t index = 0) {
        ListNode<T>* temp = head;
        ListNode<T>* node = nullptr;
        T elem = 0;
        while (temp->next != nullptr) {
            if (index == 0) {
                node = temp->next;
                temp->next = node->next;
                elem = node->data;
                delete node;
                break;
            }
            --index;
            temp = temp->next;
        }
        return elem;
    }

    void printList() {
        ListNode<T>* temp = head->next;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    bool empty() { return head->next == nullptr; }

    void destoryList() {
        ListNode<T>* temp = head->next;
        while (temp != nullptr) {
            head->next = temp->next;
            delete temp;
            temp = head->next;
        }
    }
};