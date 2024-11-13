#include "funcs.hpp"



vector<int> algo::findEulerianCycle(Graph g){
    vector<int> circuit; // 0 1 2 0
    if (!isEulerianCycle(g)) return circuit;

    // Find a vertex with at least one edge to start
    int startVertex = -1;
    for (int i = 0; i < g.getVertices(); i++) {
        if (!adjList[i].empty()) {
            startVertex = i;
            break;
        }
    }

    stack<int> currentPath;
    vector<int> tempCircuit;
    currentPath.push(startVertex);
    int currentVertex = startVertex;

    while (!currentPath.empty()) {
        if (!adjList[currentVertex].empty()) {
            currentPath.push(currentVertex);
            int nextVertex = adjList[currentVertex].front();
            adjList[currentVertex].pop_front();
            adjList[nextVertex].remove(currentVertex);
            currentVertex = nextVertex;
        } else {
            tempCircuit.push_back(currentVertex);
            currentVertex = currentPath.top();
            currentPath.pop();
        }
    }

    reverse(tempCircuit.begin(), tempCircuit.end());
    return tempCircuit;
}

bool algo::isEulerianCycle(Graph graph){

}
void algo::dfs(int start_node, vector<bool> &visited){

}
void algo::eulerFinder(Graph graph){

}