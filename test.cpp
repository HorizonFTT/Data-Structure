#include <iostream>
#include "algorithm.hpp"

int main(int argc, char const *argv[]) {
    // List<int> list;
    // for (int i = -3; i != 5; ++i) {
    //     list.listInsert(i * i);
    //     list.listInsert(i);
    // }
    // list.printList();
    // Algorithm::splitList(list);
    // list.printList();
    // // BiTree tree = BinaryTree<int>::creatTree();
    // // tree->preOrder();
    // // std::cout << std::endl;
    // // tree->inOrder();
    // // std::cout << std::endl;
    // // tree->postOrder();
    // // std::cout << std::endl;
    // // Algorithm::levelOrder(tree);
    // // Algorithm::printPrePath(tree);
    Graph<> *graph = Graph<>::creatGraph(true, false);
    Algorithm::BFSTraverse(graph);
    Algorithm::DFSTraverse(graph);
    return 0;
}
