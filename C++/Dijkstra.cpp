#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>& adj, int src, vector<int>& dist) {
    set<pair<int, int>> pq; // Priority queue to track vertices with the minimum distance
    dist[src] = 0; // Distance to the source vertex is zero
    pq.insert({0, src}); // Insert the source vertex into the priority queue

    while (!pq.empty()) {
        int u = pq.begin()->second; // Get the vertex with the minimum distance
        pq.erase(pq.begin()); // Remove it from the priority queue

        // Explore all neighboring vertices of u
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                // Relaxation step: Update the distance to v if a shorter path is found
                pq.erase({dist[v], v});
                dist[v] = dist[u] + weight;
                pq.insert({dist[v], v});
            }
        }
    }
}
