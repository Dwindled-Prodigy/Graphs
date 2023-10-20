void removeVertex(int vertex) {
    if (vertex < 1 || vertex > V) {
        cerr << "Invalid vertex to remove." << endl;
        return;
    }

    // Remove all edges associated with the vertex
    for (int v = 1; v <= V; v++) {
        if (v == vertex) {
            continue;
        }
        vector<int>::iterator it = adjList[v - 1].begin();
        while (it != adjList[v - 1].end()) {
            if (*it == vertex) {
                adjList[v - 1].erase(it);
                break;
            }
            it++;
        }
    }

    // Remove the adjacency list of the removed vertex
    adjList[vertex - 1].clear();

    // Shift vertices to fill the gap
    for (int v = vertex - 1; v < V - 1; v++) {
        adjList[v] = adjList[v + 1];
    }

    // Reduce the number of vertices
    V--;
    adjList.pop_back();
}
