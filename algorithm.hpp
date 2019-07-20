#include "binary_tree.hpp"
#include "graph.hpp"
#include "list.hpp"
#include "queue.hpp"
#include "stack.hpp"

using LinkList = List<int>;
using SqStack = Stack<int>;
using SqQueue = Queue<int>;
using BiTree = BinaryTree<int> *;

class Algorithm {
public:
    static void splitList(LinkList &l);

    static void levelOrder(BiTree root);

    static bool printPrePath(BiTree root);

    static void BFSTraverse(Graph<> *g);

    static void DFSTraverse(Graph<> *g);

    static void DFS(Graph<> *g, int v, bool *visited);
};