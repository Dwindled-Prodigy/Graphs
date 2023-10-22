import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

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

    public void topologicalSortUtil(int v, boolean[] visited, Stack<Integer> stack) {
        visited[v] = true;

        for (int u : adjList.get(v)) {
            if (!visited[u]) {
                topologicalSortUtil(u, visited, stack);
            }
        }

        stack.push(v);
    }

    public void topologicalSort() {
        Stack<Integer> stack = new Stack<>();
        boolean[] visited = new boolean[V];

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, stack);
            }
        }

        while (!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        int V, E, u, v;

        System.out.print("Enter the number of vertices: ");
        V = 6; // Change as needed
        Graph graph = new Graph(V);

        System.out.print("Enter the number of edges: ");
        E = 6; // Change as needed

        int[][] edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}}; // Change as needed

        for (int i = 0; i < E; i++) {
            u = edges[i][0];
            v = edges[i][1];
            graph.addEdge(u, v);
        }

        System.out.print("Topological Sorting: ");
        graph.topologicalSort();
    }
}
