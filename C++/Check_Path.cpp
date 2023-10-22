#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // For an undirected graph
}

bool hasPath(vector<vector<int>>& adj, int src, int dest) {
    vector<bool> visited(adj.size(), false);
    stack<int> stack;

    visited[src] = true;
    stack.push(src);

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();

        for (int neighbor : adj[current]) {
            if (neighbor == dest) {
                return true; // Path found
            }
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                stack.push(neighbor);
            }
        }
    }

    return false; // No path found
}
