#include "algo.hpp"
#include <unistd.h>
#include <random>

using namespace algo;

void printUsage(const char *progName) {
    cout << "Usage: " << progName << " -v <number_of_vertices> -e <number_of_edges> -s <random_seed>" << endl;
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
        int node_v = dist(rng); // generate numbers in the range 0 to num_vertices - 1
        if (node_u == node_v) { // No self loops
            i--;
            continue;
        }

        if (find(g.getAdjList()[node_u].begin(), g.getAdjList()[node_u].end(), node_v) != g.getAdjList()[node_u].end()) { // No parallel edges
            // if we went over the adjacency list of node_u and found node_v, then we have a parallel edge
            i--;
            continue;
        }

        g.addEdge(node_u, node_v);
    }

    eulerFinder(g);
    g.printGraph();
    int const f = g.getEdges();
    cout << "number of edges: " << f << endl;
    return 0;
}