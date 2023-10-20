void addEdge(int src, int dest) {
    adjList[src - 1].push_back(dest);
    adjList[dest - 1].push_back(src);
}
