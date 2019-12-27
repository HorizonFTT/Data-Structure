#include "binary_tree.hpp"
#include "graph.hpp"
#include "list.hpp"
#include "queue.hpp"
#include "stack.hpp"

using LinkList = List<int>*;
using SqStack = Stack<int>;
using SqQueue = Queue<int>;
using BiTree = BinaryTree<int>*;
using DiGraph = Graph<>*;

class Algorithm {
public:
    static void splitList(LinkList l);

    static void splitByPosition(ListNode<int>*& l, ListNode<int>*& even, ListNode<int>*& odd);

    static bool judgeList(LinkList l);

    static void delSame(LinkList l);

    static void selectSortList(LinkList l);

    static LinkList factorization(unsigned num);

    static void levelOrder(BiTree root);

    static void specialInOrder(BiTree root, int depth = 1);

    static bool printPrePath(BiTree root);

    static size_t getSize(BiTree root);

    static BiTree getKRank(BiTree root, int K);

    static size_t getDepth(BiTree root);

    static size_t getWidth(BiTree root);

    static bool strictBinary(BiTree root);

    static int numOfTree(int n);

    static int numOfKDegree(BiTree root, int k);

    static BiTree createTreeByArray(int* a, int n, int i = 0);

    static void BFSTraverse(DiGraph g);

    static void DFSTraverse(DiGraph g);

    static void DFS(DiGraph g, int v, bool* visited);

    static bool judgePath(DiGraph g, int i, int j);

    static void simplePath(DiGraph g, int i, int j);

    static void findPath(DiGraph g, int beg, int end, bool* visited, int* path,
        int depth);

    static void printPath(DiGraph g, int i, int j, int k);

    static void findPath(DiGraph g, int beg, int end, bool* visited, int* path,
        int depth, int k);

    static void fuck();

    static bool judge(LinkList l);

    static void delItem(LinkList l, int item);

    static ListNode<int>* del(ListNode<int>* head, int item);

    static int getNewData(int num);

    static size_t getTreeSize(BiTree root);

    static bool inMatrix(int x);

    static void APlusB(int x);

    static int findMinSum(int* a = nullptr, int n = 0);

    static void evenOrOdd(int* a, int n);

    static int partition(int* a, int low, int high);

    static void getNDivFour(int* a, int n);

    static int findMid(int* a, int* b, int n1, int n2);
};