public void removeEdge(int src, int dest) {
    if (src < 1 || src > V || dest < 1 || dest > V) {
        System.err.println("Invalid vertices for edge removal.");
        return;
    }

    adjList.get(src - 1).remove(Integer.valueOf(dest));
    adjList.get(dest - 1).remove(Integer.valueOf(src));
}
