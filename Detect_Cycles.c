#include <stdio.h>
#include <stdbool.h>

void addEdge(int V, int adj[V][V], int u, int v) {
    adj[u][v] = 1;
}

bool hasCycleUtil(int V, int adj[V][V], int v, bool visited[V], bool stack[V]) {
    visited[v] = true;
    stack[v] = true;

    for (int u = 0; u < V; u++) {
        if (adj[v][u] == 1) {
            if (!visited[u]) {
                if (hasCycleUtil(V, adj, u, visited, stack)) {
                    return true;
                }
            } else if (stack[u]) {
                return true; // Cycle detected
            }
        }
    }

    stack[v] = false;
    return false;
}

bool hasCycle(int V, int adj[V][V]) {
    bool visited[V];
    bool stack[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        stack[i] = false;
    }

    for (int v = 0; v < V; v++) {
        if (!visited[v]) {
            if (hasCycleUtil(V, adj, v, visited, stack)) {
                return true;
            }
        }
    }

    return false;
}
