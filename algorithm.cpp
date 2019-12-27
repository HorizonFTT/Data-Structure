#include "algorithm.hpp"
#include <cstdlib>
#include <cstring>

void Algorithm::splitList(LinkList l)
{
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

void Algorithm::splitByPosition(ListNode<int>*& l, ListNode<int>*& even, ListNode<int>*& odd)
{
    if (l != nullptr) {
        ListNode<int>* node = l;
        l = l->next;
        node->next = nullptr;
        even = node;
        splitByPosition(l, odd, even->next);
    }
}

bool Algorithm::judgeList(LinkList l)
{
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

void Algorithm::delSame(LinkList l)
{
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

void Algorithm::selectSortList(LinkList l)
{
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

LinkList Algorithm::factorization(unsigned num)
{
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

void Algorithm::levelOrder(BiTree root)
{
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

void Algorithm::specialInOrder(BiTree root, int depth)
{
    if (root->lchild == nullptr && root->rchild == nullptr) {
        return;
    }
    if (root->lchild != nullptr) {
        specialInOrder(root->lchild, depth + 1);
    }
    std::cout << "data:" << root->data << " depth:" << depth << std::endl;
    if (root->rchild != nullptr) {
        specialInOrder(root->rchild, depth + 1);
    }
}

bool Algorithm::printPrePath(BiTree root)
{
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

size_t Algorithm::getSize(BiTree root)
{
    if (root == nullptr) {
        return 0;
    }
    return 1 + getSize(root->lchild) + getSize(root->rchild);
}

BiTree Algorithm::getKRank(BiTree root, int K)
{
    if (K > root->data) {
        return getKRank(root->lchild, K - root->data);
    } else if (K < root->data) {
        return getKRank(root->rchild, K);
    } else {
        return root;
    }
}

size_t Algorithm::getDepth(BiTree root)
{
    if (root == nullptr) {
        return 0;
    }
    size_t left = getDepth(root->lchild);
    size_t right = getDepth(root->rchild);
    return 1 + (left > right ? left : right);
}

size_t Algorithm::getWidth(BiTree root)
{
    if (root == nullptr) {
        return 0;
    }
    size_t child = getWidth(root->lchild) + getWidth(root->rchild);
    return 1 > child ? 1 : child;
}

bool Algorithm::strictBinary(BiTree root)
{
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

int Algorithm::numOfTree(int n)
{
    if (n == 0 || n == 1) {
        return 1;
    }
    int num = 0;
    for (int i = 0; i != n; ++i) {
        num += numOfTree(i) * numOfTree(n - 1 - i);
    }
    return num;
}

int Algorithm::numOfKDegree(BiTree root, int k)
{
    if (root == nullptr) {
        return 0;
    }
    int num = 0;
    int temp = 0;
    root = root->lchild;
    while (root != nullptr) {
        ++temp;
        num += numOfKDegree(root, k);
        root = root->rchild;
    }
    return temp == k ? num + 1 : num;
}
//             1
//      2            3
//  4   5   6     7     8
// 9      10 11

BiTree Algorithm::createTreeByArray(int* a, int n, int i)
{
    if (i >= n || a[i] == 0) {
        return nullptr;
    }
    BiTree tree = new BinaryTree<int>(a[i]);
    tree->lchild = createTreeByArray(a, n, 2 * i + 1);
    tree->rchild = createTreeByArray(a, n, 2 * i + 2);
    return tree;
}

void Algorithm::BFSTraverse(DiGraph g)
{
    size_t vexnum = g->vexnum;
    bool visited[vexnum] = { false };
    Queue<size_t> queue;
    for (size_t i = 0; i != vexnum; ++i) {
        size_t v = i;
        if (!visited[v]) {
            std::cout << g->adjlist[v]->data << " ";
            visited[v] = true;
            queue.enQueue(v);
            while (!queue.queueEmpty()) {
                queue.deQueue(v);
                for (int w = g->firstNeighbor(v); w != -1; w = g->nextNeighbor(v, w)) {
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

void Algorithm::DFSTraverse(DiGraph g)
{
    size_t vexnum = g->vexnum;
    bool visited[vexnum] = { false };
    for (size_t i = 0; i != vexnum; ++i) {
        if (!visited[i]) {
            DFS(g, i, visited);
        }
    }
    std::cout << std::endl;
}

void Algorithm::DFS(DiGraph g, int v, bool* visited)
{
    std::cout << g->adjlist[v]->data << " ";
    visited[v] = true;
    for (int w = g->firstNeighbor(v); w != -1; w = g->nextNeighbor(v, w)) {
        if (!visited[w]) {
            DFS(g, w, visited);
        }
    }
}

bool Algorithm::judgePath(DiGraph g, int i, int j)
{
    size_t vexnum = g->vexnum;
    bool visited[vexnum] = { false };
    Queue<size_t> queue;
    size_t v = i - 1;
    visited[v] = true;
    queue.enQueue(v);
    while (!queue.queueEmpty()) {
        queue.deQueue(v);
        for (int w = g->firstNeighbor(v); w != -1; w = g->nextNeighbor(v, w)) {
            if (w == j - 1) {
                return true;
            }
            if (!visited[w]) {
                visited[w] = true;
                queue.enQueue(w);
            }
        }
    }
    return false;
}

void Algorithm::simplePath(DiGraph g, int i, int j)
{
    size_t vexnum = g->vexnum;
    bool visited[vexnum] = { false };
    int path[vexnum] = { 0 };
    findPath(g, i - 1, j - 1, visited, path, 0);
}

void Algorithm::findPath(DiGraph g, int beg, int end, bool* visited, int* path,
    int depth)
{
    visited[beg] = true;
    path[depth] = beg + 1;
    if (beg == end) {
        for (int i = 0; i <= depth; ++i) {
            std::cout << path[i] << " ";
        }
        std::cout << std::endl;
        return;
    }
    for (int p = g->firstNeighbor(beg); p != -1; p = g->nextNeighbor(beg, p)) {
        if (!visited[p]) {
            findPath(g, p, end, visited, path, depth + 1);
        }
        visited[p] = false;
    }
}

void Algorithm::printPath(DiGraph g, int i, int j, int k)
{
    size_t vexnum = g->vexnum;
    bool visited[vexnum] = { false };
    int path[vexnum] = { 0 };
    std::cout << "Path:" << std::endl;
    findPath(g, i - 1, j - 1, visited, path, 0, k);
}

void Algorithm::findPath(DiGraph g, int beg, int end, bool* visited, int* path,
    int depth, int k)
{
    visited[beg] = true;
    path[depth] = beg + 1;
    if ((beg == end) && (depth == k)) {
        for (int i = 0; i <= depth; ++i) {
            std::cout << path[i] << " ";
        }
        std::cout << std::endl;
        return;
    }
    for (int p = g->firstNeighbor(beg); p != -1; p = g->nextNeighbor(beg, p)) {
        if (!visited[p]) {
            findPath(g, p, end, visited, path, depth + 1, k);
        }
        visited[p] = false;
    }
}

void Algorithm::fuck()
{
    // int a[101] = { 1 };
    // for (int i = 1; i != 101; ++i) {
    //     int lower_bound = a[i - 1];
    //     int upper_bound = 2 * lower_bound;
    //     for (int j = 0; j != i; ++j) {
    //         int temp[3] = { 2 * a[j], 3 * a[j], 5 * a[j] };
    //         for (int k = 0; k != 3; ++k) {
    //             if (temp[k] > lower_bound && temp[k] < upper_bound) {
    //                 upper_bound = temp[k];
    //             }
    //         }
    //     }
    //     a[i] = upper_bound;
    //     std::cout << lower_bound << " ";
    // }

    // int n = 0;
    // int k = 2;
    // int a[100] = {1};
    // while (n != 101) {
    //     for (int i = 0; i <= n; ++i) {
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
    // std::cout<<std::endl;
}

bool Algorithm::judge(LinkList l)
{
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

void Algorithm::delItem(LinkList l, int item)
{
    l->head->next = del(l->head->next, item);
}

ListNode<int>* Algorithm::del(ListNode<int>* node, int item)
{
    if (node == nullptr) {
        return nullptr;
    }
    ListNode<int>* last = del(node->next, item);
    if (node->data == item) {
        delete node;
        return last;
    }
    node->next = last;
    return node;
}

int Algorithm::getNewData(int num)
{
    std::cout << num << std::endl;
    int temp = 0;
    if (num / 10 == 0) {
        return 1;
    }
    do {
        temp += num % 10;
        num /= 10;
    } while (num > 0);
    return 1 + getNewData(temp);
}

size_t Algorithm::getTreeSize(BiTree root)
{
    if (root == nullptr) {
        return 0;
    }
    return 1 + getTreeSize(root->lchild) + getTreeSize(root->rchild);
}

bool Algorithm::inMatrix(int num)
{
    int mateix[5][5] = {
        1,
        2,
        3,
        4,
        5,
        3,
        4,
        6,
        7,
        8,
        4,
        7,
        9,
        10,
        11,
        5,
        8,
        10,
        15,
        20,
        6,
        10,
        14,
        17,
        21,
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

void Algorithm::APlusB(int x)
{
    int array[10] = { 1, 3, 5, 6, 8, 9, 12, 14, 16, 17 };
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

int Algorithm::findMinSum(int* a, int n)
{
    int example[6] = { 10, 20, -10, 8, -30, 20 };
    if (a == nullptr) {
        a = example;
        n = 6;
    }
    // bool negative = false;
    // int sum = 0;
    // int min = 0;
    // for (int i = 0; i != n; ++i) {
    //     if (a[i] < 0) {
    //         negative = true;
    //         if (sum > 0) {
    //             sum = a[i];
    //         } else {
    //             sum += a[i];
    //         }
    //         if (sum < min) {
    //             min = sum;
    //         }
    //         continue;
    //     }
    //     sum += a[i];
    // }
    // if (negative == false) {
    //     return 0;
    // }
    // return min;
    int mins[n - 1];
    int sum = 0;
    int min = 0;
    for (int i = 0; i != n - 1; ++i) {
        sum = a[i];
        for (int j = 1; j != n - i; ++j) {
            sum += a[i + j];
            if (sum < min) {
                min = sum;
            }
        }
        mins[i] = min;
        min = 0;
    }
    for (int i = 0; i != n - 2; ++i) {
        if (mins[i] < min) {
            min = mins[i];
        }
    }
    return min;
}

void Algorithm::evenOrOdd(int* a, int n)
{
    int even = 0, odd = 1;
    int temp;
    while (even < n && odd < n) {
        if (a[even] % 2 == 0) {
            even += 2;
            continue;
        }
        if (a[odd] % 2 == 1) {
            odd += 2;
            continue;
        }
        temp = a[even];
        a[even] = a[odd];
        a[odd] = temp;
        even += 2;
        odd += 2;
    }
}

int Algorithm::partition(int* a, int low, int high)
{
    int middle = a[low];
    while (low < high) {
        while (low < high && a[high] >= middle) {
            --high;
        }
        a[low] = a[high];
        while (low < high && a[low] <= middle) {
            ++low;
        }
        a[high] = a[low];
    }
    a[low] = middle;
    return low;
}

void Algorithm::getNDivFour(int* a, int n)
{
    int k = n / 4;
    int beg = 0;
    int end = n - 1;
    while (1) {
        int position = partition(a, beg, end);
        if (k > position + 1) {
            beg = position + 1;
        } else if (k < position + 1) {
            end = position - 1;
        } else {
            std::cout << a[k - 1] << std::endl;
            return;
        }
    }
}

int Algorithm::findMid(int* a, int* b, int n1, int n2)
{
    int f1 = 0, f2 = 0;
    while (f1 != n1 || f2 != n2) {
        int mid1 = (f1 + n1) / 2;
        int mid2 = (f2 + n2) / 2;
        if (a[mid1] == b[mid2]) {
            return a[mid1];
        } else if (a[mid1] < b[mid2]) {
            if ((f1 + n1) % 2 == 0) {
                f1 = mid1;
                n2 = mid2;
            } else {
                f1 = mid1 + 1;
                n2 = mid2;
            }
        } else {
            if ((f2 + n2) % 2 == 0) {
                f2 = mid2;
                n1 = mid1;
            } else {
                f2 = mid2 + 1;
                n1 = mid1;
            }
        }
    }
    return a[f1] < b[f2] ? a[f1] : b[f2];
    // int beg1 = 0, beg2 = 0, end1 = n1 - 1, end2 = n2 - 1;
    // while (beg1 <= end1 || beg2 <= end2) {
    //     int mid1 = (beg1 + end1) / 2;
    //     int mid2 = (beg2 + end2) / 2;
    //     if (a[mid1] == b[mid2]) {
    //         return a[mid1];
    //     } else if (a[mid1] > b[mid2]) {
    //         beg2 = mid2 + 1;
    //         end1 = mid1 - 1;
    //     } else {
    //         beg1 = mid1 + 1;
    //         end2 = mid2 - 1;
    //     }
    // }
    // return a[beg1] < b[beg2] ? a[beg1] : b[beg2];
    // return 1;
}