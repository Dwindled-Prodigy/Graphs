#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjList;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        perror("Error creating node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (!graph) {
        perror("Error creating graph");
        exit(EXIT_FAILURE);
    }
    graph->V = V;
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));
    if (!graph->adjList) {
        perror("Error creating adjacency list");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

int isDuplicateEdge(struct Graph* graph, int src, int dest) {
    struct Node* temp = graph->adjList[src - 1];
    while (temp) {
        if (temp->data == dest) {
            return 1; // Duplicate edge found
        }
        temp = temp->next;
    }
    return 0; // No duplicate edge found
}

void addEdge(struct Graph* graph, int src, int dest) {
    if (isDuplicateEdge(graph, src, dest)) {
        fprintf(stderr, "Duplicate edge found: (%d, %d)\n", src, dest);
        return;
    }

    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src - 1];
    graph->adjList[src - 1] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest - 1];
    graph->adjList[dest - 1] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int v = 1; v <= graph->V; v++) {
        printf("Vertex %d: ", v);
        for (int i = 1; i <= graph->V; i++) {
            int isNeighbor = 0;
            struct Node* temp = graph->adjList[v - 1];
            while (temp) {
                if (temp->data == i) {
                    isNeighbor = 1;
                    break;
                }
                temp = temp->next;
            }
            printf("%d ", isNeighbor);
        }
        printf("\n");
    }
}

void freeGraph(struct Graph* graph) {
    if (graph) {
        for (int i = 0; i < graph->V; i++) {
            struct Node* temp = graph->adjList[i];
            while (temp) {
                struct Node* next = temp->next;
                free(temp);
                temp = next;
            }
        }
        free(graph->adjList);
        free(graph);
    }
}

int main() {
    int V, E, src, dest;

    printf("Enter the number of vertices: ");
    if (scanf("%d", &V) != 1 || V <= 0) {
        fprintf(stderr, "Invalid input for the number of vertices.\n");
        return 1;
    }

    struct Graph* graph = createGraph(V);

    printf("Enter the number of edges: ");
    if (scanf("%d", &E) != 1 || E < 0) {
        fprintf(stderr, "Invalid input for the number of edges.\n");
        freeGraph(graph);
        return 1;
    }

    for (int i = 0; i < E; i++) {
        printf("Enter edge (source destination): ");
        if (scanf("%d %d", &src, &dest) != 2 || src < 1 || src > V || dest < 1 || dest > V) {
            fprintf(stderr, "Invalid input for an edge.\n");
            freeGraph(graph);
            return 1;
        }
        addEdge(graph, src, dest);
    }

    printGraph(graph);

    freeGraph(graph);

    return 0;
}
