#include <stdio.h>
#include <stdbool.h>

void addEdge(int V, int adj[V][V], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; // For an undirected graph
}

void DFS(int V, int adj[V][V], int v, bool visited[V]) {
    visited[v] = true;
    for (int u = 0; u < V; u++) {
        if (adj[v][u] && !visited[u]) {
            DFS(V, adj, u, visited);
        }
    }
}

bool isConnected(int V, int adj[V][V]) {
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    int startVertex = 0; // Starting vertex for DFS
    DFS(V, adj, startVertex, visited);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            return false; // If there's an unvisited vertex, the graph is not connected
        }
    }

    return true; // If all vertices are visited, the graph is connected
}
