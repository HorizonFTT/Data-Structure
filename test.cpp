#include "algorithm.hpp"
#include <cstdio>
#include <iostream>
#include <sys/time.h>

int main(int argc, char const* argv[])
{
    // LinkList l = List<int>::createList();
    // BiTree tree = BinaryTree<int>::creatTree();
    // DiGraph graph = Graph<>::creatGraph(true, false);

    struct timeval t1, t2;
    double timeuse;
    gettimeofday(&t1, NULL);

    // l->printList();
    // Algorithm::delItem(l, 5);
    // l->printList();
    // Algorithm::splitList(l);
    // l->printList();
    // Algorithm::delSame(l);
    // l->printList();
    // Algorithm::selectSortList(l);
    // l->printList();
    // Algorithm::factorization(2100)->printList();
    // std::cout << Algorithm::judgeList(l) << std::endl;
    // l->printList();
    // LinkList even = List<int>::createList(0);
    // LinkList odd = List<int>::createList(0);
    // Algorithm::splitByPosition(l->head->next,even->head->next,odd->head->next);
    // l->printList();
    // even->printList();
    // odd->printList();

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
    // Algorithm::specialInOrder(tree);
    // std::cout << Algorithm::getDepth(tree) << std::endl;
    // std::cout << Algorithm::getWidth(tree) << std::endl;
    // std::cout << Algorithm::strictBinary(tree) << std::endl;
    // std::cout << Algorithm::numOfTree(3) << std::endl;
    // std::cout << Algorithm::numOfKDegree(tree, 0) << std::endl;

    // int a[] = { 1, 2, 3, 0, 4, 0, 5, 0, 0, 6, 0 };
    // Algorithm::createTreeByArray(a, 11)->preOrder();

    // Algorithm::BFSTraverse(graph);
    // Algorithm::DFSTraverse(graph);
    // Algorithm::simplePath(graph, 1, 4);
    // Algorithm::printPath(graph, 1, 4, 2);

    // std::cout << Algorithm::judgePath(graph, 3, 1) << std::endl;
    // std::cout << Algorithm::judgePath(graph, 2, 1) << std::endl;

    // std::cout << Algorithm::getNewData(345) << std::endl;
    // Algorithm::fuck();
    // std::cout << Algorithm::findMinSum() << std::endl;

    // for (int i = 0; i != 30; ++i) {
    //     Algorithm::APlusB(i);
    //     std::cout << Algorithm::inMatrix(i) << std::endl;
    // }
    // int a[] = { 2, 4, 1, 3, 5};
    // Algorithm::evenOrOdd(a, sizeof(a) / sizeof(int));
    // for (auto i : a) {
    //     std::cout << i << " ";
    // }
    // std::cout << std::endl;
    // int a[] = { 9, 3, 2, 5, 7, 1, 4, 8, 6 };
    // Algorithm::getNDivFour(a, sizeof(a) / sizeof(int));
    int a[] = { 1, 3, 4 };
    int b[] = { 1, 2, 5, 6, 7, 8 };
    //1 1 2 5 6
    std::cout << Algorithm::findMid(a, b, 3, 6) << std::endl;
    gettimeofday(&t2, NULL);
    timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec) / 1000000.0;
    printf("Use Time:%f\n", timeuse);
    return 0;
}