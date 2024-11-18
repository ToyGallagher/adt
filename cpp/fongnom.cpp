#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent a graph
struct Graph {
    vector<vector<int>> adjacencyList;
    vector<int> color;

    Graph(int size) : adjacencyList(size + 1), color(size + 1, -1) {}
};

bool isBipartite(const Graph& graph, int startNode) {
    queue<int> q;
    q.push(startNode);
    graph.color[startNode] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph.adjacencyList[u]) {
            if (graph.color[v] == -1) {
                graph.color[v] = 1 - graph.color[u];
                q.push(v);
            } else if (graph.color[v] == graph.color[u]) {
                return false;  // Not Bipartite
            }
        }
    }

    return true;  // Bipartite
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int nodes, edges;
        cin >> nodes >> edges;

        Graph graph(nodes);

        while (edges--) {
            int a, b;
            cin >> a >> b;
            graph.adjacencyList[a].push_back(b);
            graph.adjacencyList[b].push_back(a);
        }

        bool result = isBipartite(graph, 1);

        cout << (result ? "yes" : "no") << "\n";
    }

    return 0;
}
