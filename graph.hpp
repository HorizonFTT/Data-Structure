#include <iostream>

class Algorithm;

template <typename T>
class ArcNode {
    template <typename Q, typename W>
    friend class Graph;
    friend class Algorithm;

private:
    size_t adjvex;
    ArcNode<T> *next;
    T weight;

public:
    ArcNode(size_t v, ArcNode<T> *n, T w) : adjvex(v), next(n), weight(w) {}
};

template <typename T, typename E>
class VNode {
    template <typename Q, typename W>
    friend class Graph;
    friend class Algorithm;

private:
    T data;
    ArcNode<E> *first = nullptr;
    size_t arcnum;

public:
    VNode(T d, bool weighted) : data(d) {
        int arcdata;
        T weight;
        ArcNode<E> *temp;
        while (1) {
            std::cin >> arcdata;
            if (arcdata == 0) {
                break;
            }
            weight = 1;
            if (weighted == true) {
                std::cin >> weight;
            }
            temp = new ArcNode<E>(arcdata - 1, first, weight);
            first = temp;
            ++arcnum;
        }
    }
};

template <typename T = int, typename E = int>
class Graph {
    friend class Algorithm;

    static const size_t MAXVERTEXNUM = 100;
    static const T vexend = std::is_same<char, T>::value ? '#' : 0;

private:
    VNode<T, E> *adjlist[MAXVERTEXNUM];
    size_t vexnum = 0;
    size_t arcnum = 0;
    bool directed;
    bool weighted;

    Graph(bool d = true, bool w = true) : directed(d), weighted(w){};

public:
    static Graph<T, E> *creatGraph(bool d = true, bool w = true) {
        Graph<T, E> *graph = new Graph(d, w);
        VNode<T, E> *vnode;
        T vexdata;
        for (int i = 0; i != MAXVERTEXNUM; ++i) {
            std::cin >> vexdata;
            if (vexdata == vexend) {
                break;
            }
            vnode = new VNode<T, E>(vexdata, w);
            graph->adjlist[i] = vnode;
            graph->arcnum += vnode->arcnum;
            ++(graph->vexnum);
        }
        return graph;
    }

    bool adjacent(size_t x, size_t y) {
        if (x >= vexnum || y >= vexnum) {
            return false;
        }
        ArcNode<E> *anode = adjlist[x]->first;
        while (anode != nullptr) {
            if (anode->adjvex == y) {
                return true;
            }
            anode = anode->next;
        }
        return false;
    }

    void neightbors(size_t x) {
        if (x >= vexnum) {
            return;
        }
        ArcNode<E> *anode = adjlist[x];
        while (anode != nullptr) {
            std::cout << anode->adjvex << " ";
            anode = anode->next;
        }
        std::cout << std::endl;
    }

    bool insertVertex(T x) {
        if (vexnum != MAXVERTEXNUM) {
            VNode<T, E> *vnode = new VNode<T, E>(x, weighted);
            adjlist[vexnum] = vnode;
            arcnum += vnode->arcnum;
            ++vexnum;
            return true;
        }
        return false;
    }

    bool deleteVertex(T x) {
        for (int i = 0; i != vexnum; ++i) {
            if (adjlist[i]->data == x) {
                VNode<T, E> *vnode = adjlist[i];
                for (int j = i; j != vexnum - 1; ++j) {
                    adjlist[j] = adjlist[j + 1];
                }
                arcnum -= vnode->arcnum;
                --vexnum;
                delete vnode;
                return true;
            }
        }
        return false;
    }

    bool addEdge(size_t x, size_t y) {
        if (x >= vexnum || y >= vexnum) {
            return false;
        }
        VNode<T, E> *vnode = adjlist[x];
        E weight = 1;
        if (weighted == true) {
            std::cin >> weight;
        }
        ArcNode<E> *temp = new ArcNode<E>(y, vnode->first, weight);
        vnode->first = temp;
        ++(vnode->arcnum);
        ++arcnum;
        return true;
    }

    bool removeEdge(size_t x, size_t y) {
        if (x >= vexnum || y >= vexnum) {
            return false;
        }
        VNode<T, E> *vnode = adjlist[x];
        ArcNode<E> *anode = vnode->first;
        ArcNode<E> *temp = nullptr;
        while (anode != nullptr) {
            if (anode->adjvex == y) {
                if (temp == nullptr) {
                    vnode->first = nullptr;
                } else {
                    temp->next = anode->next;
                }
                delete anode;
                --(vnode->arcnum);
                --arcnum;
                return true;
            }
            temp = anode;
            anode = anode->next;
        }
        return false;
    }

    size_t firstNeighbor(size_t x) {
        if (x >= vexnum) {
            return false;
        }
        ArcNode<E> *anode = adjlist[x]->first;
        return anode == nullptr ? 0 : anode->adjvex;
    }

    size_t nextNeighbor(size_t x, size_t y) {
        if (x >= vexnum || y >= vexnum) {
            return false;
        }
        ArcNode<E> *anode = adjlist[x]->first;
        while (anode != nullptr) {
            if (anode->adjvex == y) {
                anode = anode->next;
                return anode == nullptr ? 0 : anode->adjvex;
            }
            anode = anode->next;
        }
        return 0;
    }

    E getEdgeValue(size_t x, size_t y) {
        if (x >= vexnum) {
            return 0;
        }
        ArcNode<E> *anode = adjlist[x]->first;
        while (anode != nullptr) {
            if (anode->adjvex == y) {
                return anode->weight;
            }
            anode = anode->next;
        }
        return 0;
    }

    bool setEdgeValue(size_t x, size_t y, E w) {
        if (x >= vexnum) {
            return false;
        }
        ArcNode<E> *anode = adjlist[x]->first;
        while (anode != nullptr) {
            if (anode->adjvex == y) {
                anode->weight = w;
                return true;
            }
            anode = anode->next;
        }
        return false;
    }
};
