#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adjList;

    Graph(int V) : V(V) {
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& stack) {
        visited[v] = true;

        for (int u : adjList[v]) {
            if (!visited[u]) {
                topologicalSortUtil(u, visited, stack);
            }
        }

        stack.push(v);
    }

    void topologicalSort() {
        stack<int> stack;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, stack);
            }
        }

        while (!stack.empty()) {
            cout << stack.top() << " ";
            stack.pop();
        }
    }
};

int main() {
    int V, E, u, v;

    cout << "Enter the number of vertices: ";
    cin >> V;
    Graph graph(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    for (int i = 0; i < E; i++) {
        cout << "Enter edge (source destination): ";
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    cout << "Topological Sorting: ";
    graph.topologicalSort();

    return 0;
}
