#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

bool hasCycleUtil(vector<vector<int>>& adj, int v, vector<bool>& visited, vector<bool>& stack) {
    visited[v] = true;
    stack[v] = true;

    for (int u : adj[v]) {
        if (!visited[u]) {
            if (hasCycleUtil(adj, u, visited, stack)) {
                return true;
            }
        } else if (stack[u]) {
            return true; // Cycle detected
        }
    }

    stack[v] = false;
    return false;
}

bool hasCycle(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    vector<bool> stack(V, false);

    for (int v = 0; v < V; v++) {
        if (!visited[v]) {
            if (hasCycleUtil(adj, v, visited, stack)) {
                return true;
            }
        }
    }

    return false;
}
