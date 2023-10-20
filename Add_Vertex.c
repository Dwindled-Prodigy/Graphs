void addVertex(struct Graph* graph) {
    graph->V++; // Increase the number of vertices
    graph->adjList = (struct Node**)realloc(graph->adjList, graph->V * sizeof(struct Node*));
    if (!graph->adjList) {
        perror("Error adding a vertex");
        exit(EXIT_FAILURE);
    }
    graph->adjList[graph->V - 1] = NULL; // Initialize the new vertex's adjacency list
}
