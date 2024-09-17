#include "Graph.hpp"


using namespace std;

Graph::Graph(int vertices) : vertices(vertices), edges(0) {
    adjList.resize(vertices);
}

void Graph::addEdge(int node_u, int node_v) {
    adjList[node_u].push_back(node_v);
    adjList[node_v].push_back(node_u);
    edges++;
}

vector<int> Graph::findEulerianCycle() {
    vector<int> circuit;
    if (!isEulerianCycle()) return circuit;

    // Find a vertex with at least one edge to start
    int startVertex = -1;
    for (int i = 0; i < vertices; i++) {
        if (!adjList[i].empty()) {
            startVertex = i;
            break;
        }
    }
    if (startVertex == -1) return circuit; // No edges in the graph

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


bool Graph::isEulerianCycle() {
    // check if all vertices with none zero degree are connected
    vector<bool> visited(vertices, false);
    int nonZeroDegreeVertex = -1;
    // Find the first vertex with non-zero degree
    for (int i = 0; i < vertices; i++) {
        if (!adjList[i].empty()) {
            nonZeroDegreeVertex = i;
            break;
        }
    }
    if (nonZeroDegreeVertex == -1) return false; // No edges in the graph

    dfs(nonZeroDegreeVertex, visited);

    for (int i = 0; i < vertices; i++) {
        if (!adjList[i].empty() && !visited[i]) return false;
    }

    // Check if all vertices have even degree
    for (int i = 0; i < vertices; i++) {
        if (adjList[i].size() % 2 != 0) return false;
    }

    return true;
}

void Graph::dfs(int start_node, vector<bool> &visited) {
    visited[start_node] = true;
    for (int neighbor: adjList[start_node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited);
        }
    }
}

void Graph::eulerFinder() {
    vector<int> eulerianCycle = findEulerianCycle();
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

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);


// TODO - remove the part below from the main function.
    g.eulerFinder();
    return 0;
}