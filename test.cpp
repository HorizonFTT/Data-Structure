#include <sys/time.h>
#include <cstdio>
#include <iostream>
#include "algorithm.hpp"

int main(int argc, char const *argv[]) {
    // LinkList l = List<int>::createList();
    // BiTree tree = BinaryTree<int>::creatTree();
    // DiGraph graph = Graph<>::creatGraph(true, false);

    struct timeval t1, t2;
    double timeuse;
    gettimeofday(&t1, NULL);

    // l->printList();
    // Algorithm::delItem(l, 1);
    // // l->printList();
    // Algorithm::splitList(l);
    // l->printList();
    // Algorithm::delSame(l);
    // l->printList();
    // Algorithm::selectSortList(l);
    // l->printList();
    // Algorithm::factorization(2100)->printList();
    // std::cout << Algorithm::judgeList(l) << std::endl;

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
    // std::cout << Algorithm::getDepth(tree) << std::endl;
    // std::cout << Algorithm::strictBinary(tree) << std::endl;

    // Algorithm::BFSTraverse(graph);
    // Algorithm::DFSTraverse(graph);
    // Algorithm::simplePath(graph, 1, 4);
    // std::cout << Algorithm::judgePath(graph, 3, 1) << std::endl;
    // std::cout << Algorithm::judgePath(graph, 2, 1) << std::endl;

    // Algorithm::fuck();
    // std::cout << Algorithm::findMinSum() << std::endl;

    // for (int i = 0; i != 30; ++i) {
    //     Algorithm::APlusB(i);
    //     std::cout << Algorithm::inMatrix(i) << std::endl;
    // }

    

    gettimeofday(&t2, NULL);
    timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec) / 1000000.0;
    printf("Use Time:%f\n", timeuse);
    return 0;
}
