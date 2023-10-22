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

    public boolean hasPath(int src, int dest) {
        boolean[] visited = new boolean[V];
        List<Integer> queue = new ArrayList<>();

        visited[src] = true;
        queue.add(src);

        while (!queue.isEmpty()) {
            int current = queue.remove(0);

            for (int neighbor : adjList.get(current)) {
                if (neighbor == dest) {
                    return true; // Path found
                }
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(neighbor);
                }
            }
        }

        return false; // No path found
    }
}
