def dijkstra(V, src, graph):
    dist = [float('inf')] * V
    sptSet = [False] * V
    dist[src] = 0

    for count in range(V - 1):
        u, min_dist = -1, float('inf')
        for v in range(V):
            if not sptSet[v] and dist[v] <= min_dist:
                min_dist = dist[v]
                u = v
        sptSet[u] = True

        for v in range(V):
            if not sptSet[v] and graph[u][v] != 0 and dist[u] != float('inf') and dist[u] + graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph[u][v]

    return dist
