void removeVertex(struct Graph* graph, int vertex) {
    if (vertex < 1 || vertex > graph->V) {
        fprintf(stderr, "Invalid vertex to remove.\n");
        return;
    }

    // Remove all edges associated with the vertex
    for (int v = 1; v <= graph->V; v++) {
        if (v == vertex) {
            continue;
        }
        struct Node* prev = NULL;
        struct Node* curr = graph->adjList[v - 1];
        while (curr) {
            if (curr->data == vertex) {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    graph->adjList[v - 1] = curr->next;
                }
                free(curr);
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    // Free the adjacency list of the removed vertex
    struct Node* temp = graph->adjList[vertex - 1];
    while (temp) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }

    // Shift vertices to fill the gap
    for (int v = vertex - 1; v < graph->V - 1; v++) {
        graph->adjList[v] = graph->adjList[v + 1];
    }

    // Reduce the number of vertices
    graph->V--;
    graph->adjList = (struct Node**)realloc(graph->adjList, graph->V * sizeof(struct Node*));
}
