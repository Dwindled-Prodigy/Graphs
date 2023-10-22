#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adjList;
    vector<int> traversalPath;

    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int src, int dest) {
        adjList[src - 1].push_back(dest);
        adjList[dest - 1].push_back(src); // For undirected graph, add the reverse edge
    }

    void BFS(int startVertex) {
        vector<bool> visited(V, false);
        queue<int> queue;

        visited[startVertex - 1] = true;
        queue.push(startVertex);

        while (!queue.empty()) {
            int currentVertex = queue.front();
            traversalPath.push_back(currentVertex);
            queue.pop();

            for (int adjVertex : adjList[currentVertex - 1]) {
                if (!visited[adjVertex - 1]) {
                    visited[adjVertex - 1] = true;
                    queue.push(adjVertex);
                }
            }
        }
    }

    void printGraph() {
        for (int v = 1; v <= V; v++) {
            cout << "Vertex " << v << ": ";
            for (int i = 1; i <= V; i++) {
                bool isNeighbor = false;
                for (int neighbor : adjList[v - 1]) {
                    if (neighbor == i || find(adjList[i - 1].begin(), adjList[i - 1].end(), v) != adjList[i - 1].end()) {
                        isNeighbor = true;
                        break;
                    }
                }
                cout << isNeighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E, src, dest;

    cout << "Enter the number of vertices: ";
    cin >> V;
    Graph graph(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    for (int i = 0; i < E; i++) {
        cout << "Enter edge (source destination): ";
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    cout << "Starting vertex for BFS: ";
    int startVertex;
    cin >> startVertex;

    graph.BFS(startVertex);

    cout << "Breadth-First Search (BFS) starting from vertex " << startVertex << ":\n";
    cout << "Traversal path: ";
    for (int i = 0; i < graph.traversalPath.size(); i++) {
        cout << graph.traversalPath[i];
        if (i < graph.traversalPath.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;

    cout << "Adjacency Graph:\n";
    graph.printGraph();

    return 0;
}
