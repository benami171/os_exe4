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

vector<int> Graph::findEulerianCycle() {
    vector<int> circuit; // 0 1 2 0
    if (!isEulerianCycle()) return circuit;

    // Find a vertex with at least one edge to start
    int startVertex = -1;
    for (int i = 0; i < vertices; i++) {
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
        if (!adjList[currentVertex].empty()) { // while still has neighbors.
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
            nonZeroDegreeVertex = i; // the index of the vertex that has non-zero degree
            break;
        }
    }
    // TODO - decide what to do in case all the vertices has degree 0.
    if (nonZeroDegreeVertex == -1) return false; // No edges in the graph
    dfs(nonZeroDegreeVertex, visited);

    for (int i = 0; i < vertices; i++) {
        if (!adjList[i].empty() && !visited[i]) return false;
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

const vector<list<int>> &Graph::getAdjList() const {
    return adjList;
}

int Graph::getEdges() const {
    return edges;
}

int Graph::getVertices() const {
    return vertices;
}

vector<list<int>>* Graph::getAdjList(){
    return &adjList;
}

void printUsage(const char *progName) {
    cout << "Usage: " << progName << " -v <number_of_vertices> -e <number_of_edges> -s <random_seed>" << endl;
}

void Graph::printGraph(const Graph &g) {
    for (int i = 0; i < g.getAdjList().size(); i++) {
        cout << i << ": ";
        for (int neighbor: g.getAdjList()[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {

    int num_vertices = 0, num_edges = 0, seed = 0;
    int opt;

    while (( opt = getopt(argc, argv, "v:e:s:")) != -1) {
        switch (opt) {
            case 'v':
                num_vertices = atoi(optarg);
                break;
            case 'e':
                num_edges = atoi(optarg);
                break;
            case 's':
                seed = atoi(optarg);
                break;
            default:
                printUsage(argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (num_edges > num_vertices * (num_vertices - 1) / 2) {
        cout << "Number of edges is greater than the maximum possible number of edges in a graph with " << num_vertices << " vertices." << endl;
        exit(EXIT_FAILURE);
    }

    seed = clock();
    Graph g(num_vertices);

    mt19937 rng(seed); // seed the generator
    uniform_int_distribution<int> dist(0, num_vertices - 1); // define the range

    for (int i = 0; i < num_edges; i++) {
        int node_u = dist(rng); // generate numbers in the range 0 to num_vertices - 1
        int node_v = dist(rng); 
        if (node_u == node_v) { // No self loops
            i--;
            continue;
        }

        if (find(g.getAdjList()[node_u].begin(), g.getAdjList()[node_u].end(), node_v) != g.getAdjList()[node_u].end()) {
            // if we went over the adjacency list of node_u and found node_v, then we have a parallel edge
            i--;
            continue;
        }

        g.addEdge(node_u, node_v);
    }

    g.eulerFinder();
    g.printGraph(g);
    int const f = g.getEdges();
    cout << "number of edges: " << f << endl;
    return 0;
}
