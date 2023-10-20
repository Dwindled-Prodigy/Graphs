import java.util.ArrayList;
import java.util.Stack;
import java.util.List;

class Graph {
    private int V;
    private List<List<Integer>> adjList;
    private List<Integer> traversalPath;

    public Graph(int V) {
        this.V = V;
        adjList = new ArrayList<>(V);
        for (int i = 0; i < V; i++) {
            adjList.add(new ArrayList<>());
        }
        traversalPath = new ArrayList<>();
    }

    public void addEdge(int src, int dest) {
        adjList.get(src - 1).add(dest);
        adjList.get(dest - 1).add(src); // For undirected graph, add the reverse edge
    }

    public void DFS(int startVertex) {
        boolean[] visited = new boolean[V];
        traversalPath.clear();
        DFSUtil(startVertex, visited);
    }

    private void DFSUtil(int vertex, boolean[] visited) {
        visited[vertex - 1] = true;
        traversalPath.add(vertex);

        for (int adjVertex : adjList.get(vertex - 1)) {
            if (!visited[adjVertex - 1]) {
                DFSUtil(adjVertex, visited);
            }
        }
    }

    public void printGraph() {
        for (int v = 1; v <= V; v++) {
            System.out.print("Vertex " + v + ": ");
            for (int i = 1; i <= V; i++) {
                boolean isNeighbor = false;
                for (int neighbor : adjList.get(v - 1)) {
                    if (neighbor == i || adjList.get(i - 1).contains(v)) {
                        isNeighbor = true;
                        break;
                    }
                }
                System.out.print(isNeighbor + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int V, E, src, dest;

        System.out.print("Enter the number of vertices: ");
        V = Integer.parseInt(System.console().readLine());
        Graph graph = new Graph(V);

        System.out.print("Enter the number of edges: ");
        E = Integer.parseInt(System.console().readLine());

        for (int i = 0; i < E; i++) {
            System.out.print("Enter edge (source destination): ");
            src = Integer.parseInt(System.console().readLine());
            dest = Integer.parseInt(System.console().readLine());
            graph.addEdge(src, dest);
        }

        System.out.print("Starting vertex for DFS: ");
        int startVertex = Integer.parseInt(System.console().readLine());

        graph.DFS(startVertex);

        System.out.println("Depth-First Search (DFS) starting from vertex " + startVertex + ":");
        System.out.print("Traversal path: ");
        for (int i = 0; i < graph.traversalPath.size(); i++) {
            System.out.print(graph.traversalPath.get(i));
            if (i < graph.traversalPath.size() - 1) {
                System.out.print(" -> ");
            }
        }
        System.out.println();

        System.out.println("Adjacency Graph:");
        graph.printGraph();
    }
}
