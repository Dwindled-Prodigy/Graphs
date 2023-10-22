public void removeVertex(int vertex) {
    if (vertex < 1 || vertex > V) {
        System.err.println("Invalid vertex to remove.");
        return;
    }

    // Remove all edges associated with the vertex
    for (int v = 1; v <= V; v++) {
        if (v == vertex) {
            continue;
        }
        adjList.get(v - 1).remove(Integer.valueOf(vertex));
    }

    // Remove the adjacency list of the removed vertex
    adjList.remove(vertex - 1);

    // Shift vertices to fill the gap
    for (int v = vertex - 1; v < V - 1; v++) {
        adjList.set(v, adjList.get(v + 1));
    }

    // Reduce the number of vertices
    V--;
}
