#include "algorithm.hpp"

void Algorithm::splitList(LinkList l) {
    auto node = l->head->next;
    size_t zero = 0;

    size_t len = l->length();
    for (size_t i = 0; i != len; ++i) {
        auto data = node->data;
        node = node->next;
        if (data < 0) {
            l->listDelete(i);
            l->listInsert(data, 0);
            ++zero;
        }
        if (data == 0) {
            l->listDelete(i);
            l->listInsert(data, zero);
        }
    }
}

bool Algorithm::judgeList(LinkList l) {
    auto node = l->head->next;
    while (node != nullptr) {
        if (node->data % 2 == 0) {
            node = node->next;
            while (node != nullptr) {
                if (node->data % 2 == 1) {
                    return false;
                }
                node = node->next;
            }
        } else {
            node = node->next;
        }
    }
    return true;
}

void Algorithm::delSame(LinkList l) {
    auto node = l->head->next;
    while (node != nullptr) {
        auto temp = node;
        while (temp->next != nullptr) {
            if (temp->next->data == node->data) {
                auto same = temp->next;
                temp->next = same->next;
                delete same;
            } else {
                temp = temp->next;
            }
        }
        node = node->next;
    }
}

void Algorithm::selectSortList(LinkList l) {
    auto node = l->head->next;
    while (node != nullptr) {
        auto temp = node->next;
        auto min = node;
        while (temp != nullptr) {
            if (temp->data < min->data) {
                min = temp;
            }
            temp = temp->next;
        }
        auto t = node->data;
        node->data = min->data;
        min->data = t;
        node = node->next;
    }
}

LinkList Algorithm::factorization(unsigned num) {
    LinkList l = new List<int>();
    if (num == 1 || num == 0) {
        l->listInsert(num);
        return l;
    }
    do {
        for (unsigned i = 2; i <= num; ++i) {
            if (num % i == 0) {
                l->listInsert(i);
                num /= i;
                break;
            }
        }
    } while (num != 1);
    return l;
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

size_t Algorithm::getSize(BiTree root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + getSize(root->lchild) + getSize(root->rchild);
}

BiTree Algorithm::getKRank(BiTree root, int K) {
    if (K > root->data) {
        return getKRank(root->lchild, K - root->data);
    } else if (K < root->data) {
        return getKRank(root->rchild, K);
    } else {
        return root;
    }
}

size_t Algorithm::getDepth(BiTree root) {
    if (root == nullptr) {
        return 0;
    }
    size_t left = getDepth(root->lchild);
    size_t right = getDepth(root->rchild);
    return 1 + (left > right ? left : right);
}

bool Algorithm::strictBinary(BiTree root) {
    if (root == nullptr) {
        return true;
    }
    if (strictBinary(root->lchild) && strictBinary(root->rchild)) {
        if (root->lchild && root->rchild) {
            return true;
        }
        if ((root->lchild == nullptr) && (root->rchild == nullptr)) {
            return true;
        }
    }
    return false;
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

void Algorithm::fuck() {
    int a[101] = {1};
    for (int i = 1; i != 101; ++i) {
        int lower_bound = a[i - 1];
        int upper_bound = 2 * lower_bound;
        for (int j = 0; j != i; ++j) {
            int x = 2 * a[j], y = 3 * a[j], z = 5 * a[j];
            if (x > lower_bound && x < upper_bound) {
                upper_bound = x;
            }
            if (y > lower_bound && y < upper_bound) {
                upper_bound = y;
            }
            if (z > lower_bound && z < upper_bound) {
                upper_bound = z;
            }
        }
        a[i] = upper_bound;
        std::cout << lower_bound << " ";
    }

    // int n = 0;
    // int k = 2;
    // int a[100] = {1};
    // while (n != 100) {
    //     for (int i = 0; i <= n; --i) {
    //         if (k == 2 * a[i] || k == 3 * a[i] || k == 5 * a[i]) {
    //             a[++n] = k;
    //             break;
    //         }
    //     }
    //     ++k;
    // }
    // for (int i = 0; i != 100; ++i) {
    //     std::cout << a[i] << " ";
    // }
}

bool Algorithm::judge(LinkList l) {
    auto temp = l->head;
    while (temp != nullptr) {
        temp = temp->next;
        if (temp != nullptr && temp->data % 2 == 0) {
            break;
        }
    }
    while (temp != nullptr) {
        temp = temp->next;
        if (temp != nullptr && temp->data % 2 == 1) {
            return false;
        }
    }
    return true;
}

void Algorithm::delItem(LinkList l, int item) { del(l->head, item); }

void Algorithm::del(ListNode<int> *head, int item) {
    auto node = head->next;
    if (node == nullptr) {
        return;
    }
    if (node->data == item) {
        head->next = node->next;
        delete node;
        del(head, item);
    } else {
        del(head->next, item);
    }
}

int Algorithm::getNewData(int data) {
    int num = data;
    int temp = 0;
    if (num / 10 == 0) {
        return 1;
    }
    do {
        temp = temp + num % 10;
        num = num / 10;
    } while (num > 0);
    return 1 + getNewData(temp);
}

size_t Algorithm::getTreeSize(BiTree root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + getTreeSize(root->lchild) + getTreeSize(root->rchild);
}

bool Algorithm::inMatrix(int num) {
    int mateix[5][5] = {
        1,  2,  3, 4, 5,  3,  4,  6, 7,  8,  4,  7,  9,
        10, 11, 5, 8, 10, 15, 20, 6, 10, 14, 17, 21,
    };
    int x = 0, y = 4;
    while (x != 5 && y != -1) {
        if (num > mateix[x][y]) {
            ++x;
        } else if (num < mateix[x][y]) {
            --y;
        } else {
            return true;
        }
    }
    return false;
}

void Algorithm::APlusB(int x) {
    int array[10] = {1, 3, 5, 6, 8, 9, 12, 14, 16, 17};
    for (int i = 0, j = 9; i != j; ++i) {
        int a = array[i];
        int b = x - a;
        while (array[j] > b && i + 1 != j) {
            --j;
        }
        if (array[j] == b) {
            std::cout << a << " + " << b << " = " << x << std::endl;
            return;
        }
    }
    std::cout << "none" << std::endl;
}
