#include <iostream>
#include <vector>

class Graph {
public:
    int V;
    std::vector<std::vector<int>> adjList;
    std::vector<int> discoveryTime;
    std::vector<int> lowTime;
    std::vector<int> parent;
    std::vector<bool> isCutVertex;
    std::vector<std::vector<int>> cutEdges;
    int time;

    Graph(int V) : V(V), adjList(V), discoveryTime(V, -1), lowTime(V, -1), parent(V, -1), isCutVertex(V, false), time(0) {
        for (int i = 0; i < V; i++) {
            adjList[i].resize(V);
        }
    }

    void addEdge(int u, int v) {
        adjList[u - 1][v - 1] = 1;
        adjList[v - 1][u - 1] = 1;
    }

    void findCutVertices(int u) {
        int children = 0;
        discoveryTime[u - 1] = lowTime[u - 1] = time;
        time++;

        for (int v = 1; v <= V; v++) {
            if (adjList[u - 1][v - 1] == 1) {
                if (discoveryTime[v - 1] == -1) {
                    children++;
                    parent[v - 1] = u;
                    findCutVertices(v);
                    lowTime[u - 1] = std::min(lowTime[u - 1], lowTime[v - 1]);
                    if (lowTime[v - 1] >= discoveryTime[u - 1] && parent[u - 1] != -1) {
                        isCutVertex[u - 1] = true;
                    }
                    if (lowTime[v - 1] > discoveryTime[u - 1]) {
                        cutEdges.push_back({u, v});
                    }
                } else if (v != parent[u - 1]) {
                    lowTime[u - 1] = std::min(lowTime[u - 1], discoveryTime[v - 1]);
                }
            }
        }

        if (parent[u - 1] == -1 && children > 1) {
            isCutVertex[u - 1] = true;
        }
    }
};

int main() {
    int V, E, u, v;

    std::cout << "Enter the number of vertices: ";
    std::cin >> V;
    Graph graph(V);

    std::cout << "Enter the number of edges: ";
    std::cin >> E;

    for (int i = 0; i < E; i++) {
        std::cout << "Enter edge (source destination): ";
        std::cin >> u >> v;
        graph.addEdge(u, v);
    }

    for (int i = 0; i < V; i++) {
        graph.discoveryTime[i] = -1;
        graph.lowTime[i] = -1;
        graph.parent[i] = -1;
    }

    for (int i = 1; i <= V; i++) {
        if (graph.discoveryTime[i - 1] == -1) {
            graph.findCutVertices(i);
        }
    }

    std::cout << "Cut Vertices: ";
    for (int i = 0; i < V; i++) {
        if (graph.isCutVertex[i]) {
            std::cout << i + 1 << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "Cut Edges: ";
    for (const auto& edge : graph.cutEdges) {
        std::cout << "(" << edge[0] << ", " << edge[1] << ") ";
    }
    std::cout << std::endl;

    return 0;
}
