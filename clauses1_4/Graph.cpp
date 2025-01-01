#include "Graph.hpp"
#include <unistd.h>
#include <random>

using namespace std;

Graph::Graph(int vertices) : vertices(vertices), edges(0) {
    adjList.resize(vertices);
}

void Graph::addEdge(int node_u, int node_v) {
    adjList[node_u].push_back(node_v);
    adjList[node_v].push_back(node_u);
    edges++;
}

int Graph::getEdges() const {
    return edges;
}

int Graph::getVertices() const {
    return vertices;
}

vector<list<int>> &Graph::getAdjList(){
    return adjList;
}