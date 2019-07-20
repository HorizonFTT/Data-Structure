#include "algorithm.hpp"

void Algorithm::splitList(LinkList &l) {
    auto pre = l.head;
    auto temp = pre->next;

    size_t len = l.length();
    for (size_t i = 0; i != len; ++i) {
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

void Algorithm::BFSTraverse(Graph<> *g) {
    size_t vexnum = g->vexnum;
    bool visited[vexnum] = {false};
    Queue<size_t> queue;
    for (size_t i = 0; i != vexnum; ++i) {
        size_t v = i;
        if (!visited[v]) {
            std::cout << g->adjlist[v]->data << " ";
            visited[v] = true;
            queue.enQueue(v);
            while (!queue.queueEmpty()) {
                queue.deQueue(v);
                for (int w = g->firstNeighbor(v); w != 0;
                     w = g->nextNeighbor(v, w)) {
                    if (!visited[w]) {
                        std::cout << g->adjlist[w]->data << " ";
                        visited[w] = true;
                        queue.enQueue(w);
                    }
                }
            }
        }
    }
    std::cout << std::endl;
}

void Algorithm::DFSTraverse(Graph<> *g) {
    size_t vexnum = g->vexnum;
    bool visited[vexnum] = {false};
    for (size_t i = 0; i != vexnum; ++i) {
        if (!visited[i]) {
            DFS(g, i, visited);
        }
    }
    std::cout << std::endl;
}

void Algorithm::DFS(Graph<> *g, int v, bool *visited) {
    std::cout << g->adjlist[v]->data << " ";
    visited[v] = true;
    for (size_t w = g->firstNeighbor(v); w != 0; w = g->nextNeighbor(v, w)) {
        if (!visited[w]) {
            DFS(g, w, visited);
        }
    }
}