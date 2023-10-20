void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src - 1];
    graph->adjList[src - 1] = newNode;

    // Add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjList[dest - 1];
    graph->adjList[dest - 1] = newNode;
}
