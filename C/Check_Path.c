#include <stdio.h>
#include <stdbool.h>

void addEdge(int V, int adj[V][V], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; // For an undirected graph
}

bool hasPath(int V, int adj[V][V], int src, int dest) {
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    int stack[V];
    int top = -1;

    visited[src] = true;
    stack[++top] = src;

    while (top >= 0) {
        int current = stack[top--];

        for (int neighbor = 0; neighbor < V; neighbor++) {
            if (adj[current][neighbor] == 1) {
                if (neighbor == dest) {
                    return true; // Path found
                }
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stack[++top] = neighbor;
                }
            }
        }
    }

    return false; // No path found
}
