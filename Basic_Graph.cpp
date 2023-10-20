#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adjList;

    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int src, int dest) {
        adjList[src - 1].push_back(dest);
        adjList[dest - 1].push_back(src);
    }

    void printGraph() {
        for (int v = 1; v <= V; v++) {
            cout << "Vertex " << v << ": ";
            for (int i = 1; i <= V; i++) {
                bool isNeighbor = false;
                for (int neighbor : adjList[v - 1]) {
                    if (neighbor == i) {
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

    graph.printGraph();

    return 0;
}
