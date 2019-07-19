#include <iostream>

class Algorithm;

template <typename T>
class BinaryTree {
    friend class Algorithm;

private:
    static const T end = std::is_same<char, T>::value ? '#' : 0;
    T data;
    BinaryTree<T> *lchild;
    BinaryTree<T> *rchild;

    BinaryTree(T elem) : data(elem) {}

public:
    static BinaryTree<T> *creatTree() {
        T elem;
        std::cin >> elem;
        if (elem == end) {
            return nullptr;
        }
        BinaryTree<T> *tree = new BinaryTree(elem);
        tree->lchild = creatTree();
        tree->rchild = creatTree();
        return tree;
    }

    void preOrder() {
        std::cout << data << " ";
        if (lchild != nullptr) {
            lchild->preOrder();
        }
        if (rchild != nullptr) {
            rchild->preOrder();
        }
    }

    void inOrder() {
        if (lchild != nullptr) {
            lchild->inOrder();
        }
        std::cout << data << " ";
        if (rchild != nullptr) {
            rchild->inOrder();
        }
    }

    void postOrder() {
        if (lchild != nullptr) {
            lchild->postOrder();
        }
        if (rchild != nullptr) {
            rchild->postOrder();
        }
        std::cout << data << " ";
    }
};
