#include "algo.hpp"
#include <utility>


vector<int> algo::findEulerianCycle(Graph& g){
    vector<int> circuit; 
    if (!isEulerianCycle(g)) return circuit;

    // Find a vertex with at least one edge to start
    int startVertex = -1;
    for (int i = 0; i < g.getVertices(); i++) {
        if (!g.getAdjList()[i].empty()) {
            startVertex = i;
            break;
        }
    }

    stack<int> currentPath;
    vector<int> tempCircuit;
    currentPath.push(startVertex);
    int currentVertex = startVertex;

    while (!currentPath.empty()) {
        if (!g.getAdjList()[currentVertex].empty()) {
            currentPath.push(currentVertex);
            int nextVertex = g.getAdjList()[currentVertex].front();
            g.getAdjList()[currentVertex].pop_front();
            g.getAdjList()[nextVertex].remove(currentVertex);
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

bool algo::isEulerianCycle(Graph& g){
    for (int i = 0; i < g.getVertices(); i++) {
        if (g.getAdjList()[i].size() % 2 != 0) {
            cout << "Vertice " << i << " has Odd Degree" << endl;
            return false;
        }
    }

    // check if all vertices with none zero degree are connected
    vector<bool> visited(g.getVertices(), false);
    int nonZeroDegreeVertex = -1;
    // Find the first vertex with non-zero degree
    for (int i = 0; i < g.getVertices(); i++) {
        if (!g.getAdjList()[i].empty()) {
            nonZeroDegreeVertex = i; // the index of the vertex that has non-zero degree
            break;
        }
    }
    // TODO - decide what to do in case all the vertices has degree 0.
    if (nonZeroDegreeVertex == -1) return false; // No edges in the graph
    
    dfs(g,nonZeroDegreeVertex, visited);
    for (int i = 0; i < g.getVertices(); i++) {
        if (!g.getAdjList()[i].empty() && !visited[i]) {
            cout << "Vertice " << i << " is non zero degree but unreachable from vertice " << nonZeroDegreeVertex
                 << endl;
            return false;
        }
    }

    return true;

}

void algo::dfs(Graph& graph, int start_node, vector<bool> &visited){
    visited[start_node] = true;
    for (int neighbor: graph.getAdjList()[start_node]) {
        if (!visited[neighbor]) {
            dfs(graph,neighbor, visited);
        }
    }
}

void algo::eulerFinder(Graph graph){
    vector<int> eulerianCycle = findEulerianCycle(graph);
    if (!eulerianCycle.empty()) {
        cout << "Eulerian Cycle: ";
        for (int v: eulerianCycle) {
            cout << v << " ";
        }
        cout << endl;
    } else {
        cout << "No Eulerian Cycle exists." << endl;
    }

}
