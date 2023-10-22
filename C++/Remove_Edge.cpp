void removeEdge(int src, int dest) {
    if (src < 1 || src > V || dest < 1 || dest > V) {
        cerr << "Invalid vertices for edge removal." << endl;
        return;
    }

    vector<int>::iterator it = adjList[src - 1].begin();
    while (it != adjList[src - 1].end()) {
        if (*it == dest) {
            adjList[src - 1].erase(it);
            break;
        }
        it++;
    }

    it = adjList[dest - 1].begin();
    while (it != adjList[dest - 1].end()) {
        if (*it == src) {
            adjList[dest - 1].erase(it);
            break;
        }
        it++;
    }
}
