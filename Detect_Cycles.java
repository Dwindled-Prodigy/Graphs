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
    }

    private boolean hasCycleUtil(int v, boolean[] visited, boolean[] stack) {
        visited[v] = true;
        stack[v] = true;

        for (int u : adjList.get(v)) {
            if (!visited[u]) {
                if (hasCycleUtil(u, visited, stack)) {
                    return true;
                }
            } else if (stack[u]) {
                return true; // Cycle detected
            }
        }

        stack[v] = false;
        return false;
    }

    public boolean hasCycle() {
        boolean[] visited = new boolean[V];
        boolean[] stack = new boolean[V];

        for (int v = 0; v < V; v++) {
            if (!visited[v]) {
                if (hasCycleUtil(v, visited, stack)) {
                    return true;
                }
            }
        }

        return false;
    }
}
