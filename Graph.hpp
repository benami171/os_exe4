#ifndef OS_EXE4_GRAPH_HPP
#define OS_EXE4_GRAPH_HPP

#include <vector>
#include <list>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {

private:
    vector<list<int>> adjList;
    int vertices;
    int edges;

public:
    explicit Graph(int vertices);
    int getEdges() const ;
    int getVertices() const;
    void printGraph();
    vector<list<int>>& getAdjList(); //
    void addEdge(int node_u, int node_v);

};



#endif
