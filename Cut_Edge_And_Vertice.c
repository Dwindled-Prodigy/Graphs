#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int V;
    int **adjList;
    int *discoveryTime;
    int *lowTime;
    int *parent;
    int *isCutVertex;
    int **cutEdges;
    int time;
};

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = (int*)malloc(V * sizeof(int));
    }
    graph->discoveryTime = (int*)malloc(V * sizeof(int));
    graph->lowTime = (int*)malloc(V * sizeof(int));
    graph->parent = (int*)malloc(V * sizeof(int));
    graph->isCutVertex = (int*)malloc(V * sizeof(int));
    graph->cutEdges = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->cutEdges[i] = (int*)malloc(2 * sizeof(int));
    }
    graph->time = 0;
    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    graph->adjList[u - 1][v - 1] = 1;
    graph->adjList[v - 1][u - 1] = 1;
}

void findCutVertices(struct Graph* graph, int u) {
    int children = 0;
    graph->discoveryTime[u - 1] = graph->lowTime[u - 1] = graph->time;
    graph->time++;

    for (int v = 1; v <= graph->V; v++) {
        if (graph->adjList[u - 1][v - 1] == 1) {
            if (graph->discoveryTime[v - 1] == -1) {
                children++;
                graph->parent[v - 1] = u;
                findCutVertices(graph, v);
                graph->lowTime[u - 1] = (graph->lowTime[u - 1] < graph->lowTime[v - 1]) ? graph->lowTime[u - 1] : graph->lowTime[v - 1];
                if (graph->lowTime[v - 1] >= graph->discoveryTime[u - 1] && graph->parent[u - 1] != -1) {
                    graph->isCutVertex[u - 1] = 1;
                }
                if (graph->lowTime[v - 1] > graph->discoveryTime[u - 1]) {
                    graph->cutEdges[u - 1][v - 1] = 1;
                }
            } else if (v != graph->parent[u - 1]) {
                graph->lowTime[u - 1] = (graph->lowTime[u - 1] < graph->discoveryTime[v - 1]) ? graph->lowTime[u - 1] : graph->discoveryTime[v - 1];
            }
        }
    }

    if (graph->parent[u - 1] == -1 && children > 1) {
        graph->isCutVertex[u - 1] = 1;
    }
}

int main() {
    int V, E, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    struct Graph* graph = createGraph(V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    for (int i = 0; i < V; i++) {
        graph->discoveryTime[i] = -1;
        graph->lowTime[i] = -1;
        graph->parent[i] = -1;
        graph->isCutVertex[i] = 0;
    }

    for (int i = 1; i <= V; i++) {
        if (graph->discoveryTime[i - 1] == -1) {
            findCutVertices(graph, i);
        }
    }

    printf("Cut Vertices: ");
    for (int i = 0; i < V; i++) {
        if (graph->isCutVertex[i]) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    printf("Cut Edges: ");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph->cutEdges[i][j]) {
                printf("(%d, %d) ", i + 1, j + 1);
            }
        }
    }
    printf("\n");

    return 0;
}
