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
    const vector<list<int>>& getAdjList() const;
    void printGraph() const;
    void addEdge(int node_u, int node_v);
    vector<int> findEulerianCycle();
    bool isEulerianCycle();
    void dfs(int start_node, vector<bool> &visited);
    void eulerFinder();
};



#endif
