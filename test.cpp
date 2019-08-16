#include <sys/time.h>
#include <iostream>
#include "algorithm.hpp"

int main(int argc, char const *argv[]) {
    struct timeval t1, t2;
    double timeuse;
    gettimeofday(&t1, NULL);

    // LinkList l = List<int>::createList();
    // l->printList();
    // Algorithm::delItem(l, 1);
    // l->printList();
    // Algorithm::splitList(l);
    // l->printList();
    // std::cout << Algorithm::judgeList(l) << std::endl;

    // BiTree tree = BinaryTree<int>::creatTree();
    // tree->preOrder();
    // std::cout << std::endl;
    // tree->inOrder();
    // std::cout << std::endl;
    // tree->postOrder();
    // std::cout << std::endl;
    // std::cout << Algorithm::getSize(tree) << std::endl;
    // Algorithm::getKRank(tree, 2)->preOrder();
    // std::cout << std::endl;
    // Algorithm::levelOrder(tree);
    // Algorithm::printPrePath(tree);

    // Graph<> *graph = Graph<>::creatGraph(true, false);
    // Algorithm::BFSTraverse(graph);
    // Algorithm::DFSTraverse(graph);

    // Algorithm::fuck();
    for (int i = 0; i != 30; ++i) {
        std::cout << Algorithm::inMatrix(i) << std::endl;
    }

    gettimeofday(&t2, NULL);
    timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec) / 1000000.0;
    printf("Use Time:%f\n", timeuse);
    return 0;
}
