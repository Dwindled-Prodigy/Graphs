void removeEdge(struct Graph* graph, int src, int dest) {
    if (src < 1 || src > graph->V || dest < 1 || dest > graph->V) {
        fprintf(stderr, "Invalid vertices for edge removal.\n");
        return;
    }

    // Remove the edge from src to dest
    struct Node* prev = NULL;
    struct Node* curr = graph->adjList[src - 1];
    while (curr) {
        if (curr->data == dest) {
            if (prev) {
                prev->next = curr->next;
            } else {
                graph->adjList[src - 1] = curr->next;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    // Remove the edge from dest to src
    prev = NULL;
    curr = graph->adjList[dest - 1];
    while (curr) {
        if (curr->data == src) {
            if (prev) {
                prev->next = curr->next;
            } else {
                graph->adjList[dest - 1] = curr->next;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}
