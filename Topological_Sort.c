#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int adj[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int topologicalOrder[MAX_VERTICES];
int topologicalIndex;

void addEdge(int u, int v) {
    adj[u][v] = 1;
}

void topologicalSortUtil(int v) {
    visited[v] = true;

    for (int u = 0; u < MAX_VERTICES; u++) {
        if (adj[v][u] && !visited[u]) {
            topologicalSortUtil(u);
        }
    }

    topologicalOrder[topologicalIndex++] = v;
}

void topologicalSort(int V) {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    topologicalIndex = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i);
        }
    }

    for (int i = topologicalIndex - 1; i >= 0; i--) {
        printf("%d ", topologicalOrder[i]);
    }
}

int main() {
    int V, E, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Topological Sorting: ");
    topologicalSort(V);

    return 0;
}
