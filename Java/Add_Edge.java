public void addEdge(int src, int dest) {
    adjList.get(src - 1).add(dest);
    adjList.get(dest - 1).add(src);
}
