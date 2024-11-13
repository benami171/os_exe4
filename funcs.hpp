#include "Graph.hpp"

namespace algo{

    vector<int> findEulerianCycle(Graph graph);
    bool isEulerianCycle(Graph graph);
    void dfs(int start_node, vector<bool> &visited);
    void eulerFinder(Graph graph);


}