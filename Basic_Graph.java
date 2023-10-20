import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Graph {
    private int V;
    private List<List<Integer>> adjList;

    public Graph(int V) {
        this.V = V;
        adjList = new ArrayList<>(V);
        for (int i = 0; i < V; i++) {
            adjList.add(new ArrayList<>());
        }
    }

    public void addEdge(int src, int dest) {
        adjList.get(src - 1).add(dest);
        adjList.get(dest - 1).add(src);
    }

    public void printGraph() {
        for (int v = 1; v <= V; v++) {
            System.out.print("Vertex " + v + ": ");
            for (int i = 1; i <= V; i++) {
                boolean isNeighbor = false;
                for (int neighbor : adjList.get(v - 1)) {
                    if (neighbor == i) {
                        isNeighbor = true;
                        break;
                    }
                }
                System.out.print((isNeighbor ? "1 " : "0 "));
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int V, E, src, dest;

        System.out.print("Enter the number of vertices: ");
        V = scanner.nextInt();

        Graph graph = new Graph(V);

        System.out.print("Enter the number of edges: ");
        E = scanner.nextInt();

        for (int i = 0; i < E; i++) {
            System.out.print("Enter edge (source destination): ");
            src = scanner.nextInt();
            dest = scanner.nextInt();
            graph.addEdge(src, dest);
        }

        graph.printGraph();
    }
}
