#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // For an undirected graph
}

void DFS(vector<vector<int>>& adj, int v, vector<bool>& visited) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            DFS(adj, u, visited);
        }
    }
}

bool isConnected(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    int startVertex = 0; // Starting vertex for DFS

    DFS(adj, startVertex, visited);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            return false; // If there's an unvisited vertex, the graph is not connected
        }
    }

    return true; // If all vertices are visited, the graph is connected
}
