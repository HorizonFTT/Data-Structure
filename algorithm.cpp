#include "algorithm.hpp"

void Algorithm::splitList(LinkList &l) {
    auto pre = l.head;
    auto temp = pre->next;

    size_t len = l.length();
    for (int i = 0; i != len; ++i) {
        auto data = temp->data;
        if (data < 0) {
            l.listInsert(data, 0);
        } else if (data > 0) {
            l.listInsert(data, len);
        } else {
            temp = temp->next;
            pre = pre->next;
            continue;
        }
        pre->next = temp->next;
        delete temp;
        temp = pre->next;
    }
}

void Algorithm::levelOrder(BiTree root) {
    Queue<BiTree> queue;
    BiTree temp;
    queue.enQueue(root);
    while (!queue.queueEmpty()) {
        queue.deQueue(temp);
        std::cout << temp->data << " ";
        if (temp->lchild != nullptr) {
            queue.enQueue(temp->lchild);
        }
        if (temp->rchild != nullptr) {
            queue.enQueue(temp->rchild);
        }
    }
    std::cout << std::endl;
}

bool Algorithm::printPrePath(BiTree root) {
    // while (root != nullptr) {
    //     if (root->lchild == nullptr && root->rchild == nullptr) {
    //         std::cout << root->data << " ";
    //         break;
    //     }
    //     while (root->rchild != nullptr) {
    //         std::cout << root->data << " ";
    //         root = root->rchild;
    //     }
    //     while (root->lchild != nullptr) {
    //         std::cout << root->data << " ";
    //         root = root->lchild;
    //     }
    // }

    if (root == nullptr) {
        return false;
    }
    std::cout << root->data << " ";
    if (printPrePath(root->rchild) == false) {
        printPrePath(root->lchild);
    }
    return true;
}

void Algorithm::BFS(Graph<> *g) {
    size_t vexnum = g->vexnum;
    bool visited[vexnum] = {false};
    Queue<int> queue;
    for (int i = 0; i != vexnum; ++i) {
        int v = i;
        if (!visited[v]) {
            std::cout << g->adjlist[v]->data << " ";
            visited[v] = true;
            queue.enQueue(v);
            while (!queue.queueEmpty()) {
                queue.deQueue(v);
                for (int w = g->firstNeighbor(v + 1); w != 0;
                     w = g->nextNeighbor(v + 1, w)) {
                    if (!visited[w - 1]) {
                        std::cout << g->adjlist[w - 1]->data << " ";
                        visited[w - 1] = true;
                        queue.enQueue(w - 1);
                    }
                }
            }
        }
    }
    std::cout << std::endl;
}