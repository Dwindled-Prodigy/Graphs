import java.util.ArrayList;
import java.util.List;

public class Graph {
    private int V;
    private List<List<Integer>> adjList;

    public Graph(int V) {
        this.V = V;
        adjList = new ArrayList<>(V);
        for (int i = 0; i < V; i++) {
            adjList.add(new ArrayList<>());
        }
    }

    public void addEdge(int u, int v) {
        adjList.get(u).add(v);
        adjList.get(v).add(u); // For an undirected graph
    }

    public void DFS(int v, boolean[] visited) {
        visited[v] = true;
        for (int u : adjList.get(v)) {
            if (!visited[u]) {
                DFS(u, visited);
            }
        }
    }

    public boolean isConnected() {
        boolean[] visited = new boolean[V];
        int startVertex = 0; // Starting vertex for DFS
        DFS(startVertex, visited);

        for (boolean visit : visited) {
            if (!visit) {
                return false; // If there's an unvisited vertex, the graph is not connected
            }
        }

        return true; // If all vertices are visited, the graph is connected
    }
}
