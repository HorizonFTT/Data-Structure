#include "binary_tree.hpp"
#include "graph.hpp"
#include "list.hpp"
#include "queue.hpp"
#include "stack.hpp"

using LinkList = List<int> *;
using SqStack = Stack<int>;
using SqQueue = Queue<int>;
using BiTree = BinaryTree<int> *;

class Algorithm {
public:
    static void splitList(LinkList l);

    static bool judgeList(LinkList l);

    static void delSame(LinkList l);

    static void selectSortList(LinkList l);

    static LinkList factorization(unsigned num);

    static void levelOrder(BiTree root);

    static bool printPrePath(BiTree root);

    static size_t getSize(BiTree root);

    static BiTree getKRank(BiTree root, int K);

    static size_t getDepth(BiTree root);

    static bool strictBinary(BiTree root);

    static void BFSTraverse(Graph<> *g);

    static void DFSTraverse(Graph<> *g);

    static void DFS(Graph<> *g, int v, bool *visited);

    static void fuck();

    static bool judge(LinkList l);

    static void delItem(LinkList l, int item);

    static void del(ListNode<int> *head, int item);

    static int getNewData(int data);

    static size_t getTreeSize(BiTree root);

    static bool inMatrix(int x);

    static void APlusB(int x);

};