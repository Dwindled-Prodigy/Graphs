import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Graph {
    int V;
    List<List<Integer>> adjList;
    List<Integer> discoveryTime;
    List<Integer> lowTime;
    List<Integer> parent;
    List<Boolean> isCutVertex;
    List<List<Integer>> cutEdges;
    int time;

    public Graph(int V) {
        this.V = V;
        adjList = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adjList.add(new ArrayList<>());
        }
        discoveryTime = new ArrayList<>();
        lowTime = new ArrayList<>();
        parent = new ArrayList<>();
        isCutVertex = new ArrayList<>();
        cutEdges = new ArrayList<>();
        time = 0;
    }

    public void addEdge(int u, int v) {
        adjList.get(u - 1).add(v);
        adjList.get(v - 1).add(u);
    }

    public void findCutVertices(int u) {
        int children = 0;
        discoveryTime.set(u - 1, time);
        lowTime.set(u - 1, time);
        time++;

        for (int v : adjList.get(u - 1)) {
            if (discoveryTime.get(v - 1) == -1) {
                children++;
                parent.set(v - 1, u);
                findCutVertices(v);
                lowTime.set(u - 1, Math.min(lowTime.get(u - 1), lowTime.get(v - 1)));
                if (lowTime.get(v - 1) >= discoveryTime.get(u - 1) && parent.get(u - 1) != -1) {
                    isCutVertex.set(u - 1, true);
                }
                if (lowTime.get(v - 1) > discoveryTime.get(u - 1)) {
                    cutEdges.add(List.of(u, v));
                }
            } else if (v != parent.get(u - 1)) {
                lowTime.set(u - 1, Math.min(lowTime.get(u - 1), discoveryTime.get(v - 1));
            }
        }

        if (parent.get(u - 1) == -1 && children > 1) {
            isCutVertex.set(u - 1, true);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int V, E, u, v;

        System.out.print("Enter the number of vertices: ");
        V = scanner.nextInt();
        Graph graph = new Graph(V);

        System.out.print("Enter the number of edges: ");
        E = scanner.nextInt();

        for (int i = 0; i < E; i++) {
            System.out.print("Enter edge (source destination): ");
            u = scanner.nextInt();
            v = scanner.nextInt();
            graph.addEdge(u, v);
        }

        for (int i = 0; i < V; i++) {
            graph.discoveryTime.add(-1);
            graph.lowTime.add(-1);
            graph.parent.add(-1);
            graph.isCutVertex.add(false);
        }

        for (int i = 1; i <= V; i++) {
            if (graph.discoveryTime.get(i - 1) == -1) {
                graph.findCutVertices(i);
            }
        }

        System.out.print("Cut Vertices: ");
        for (int i = 0; i < V; i++) {
            if (graph.isCutVertex.get(i)) {
                System.out.print(i + 1 + " ");
            }
        }
        System.out.println();

        System.out.print("Cut Edges: ");
        for (List<Integer> edge : graph.cutEdges) {
            System.out.print("(" + edge.get(0) + ", " + edge.get(1) + ") ");
        }
        System.out.println();
    }
}
