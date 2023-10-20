import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public static void dijkstra(int V, int src, int[] dist, int[][] graph) {
    Set<Integer> sptSet = new HashSet<>();
    Arrays.fill(dist, Integer.MAX_VALUE);
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1, min = Integer.MAX_VALUE;
        for (int v = 0; v < V; v++) {
            if (!sptSet.contains(v) && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }
        sptSet.add(u);

        for (int v = 0; v < V; v++) {
            if (!sptSet.contains(v) && graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}
