class Graph:
    def __init__(self, V):
        self.V = V
        self.adjList = [[] for _ in range(V)]

    def addEdge(self, u, v):
        self.adjList[u].append(v)
        self.adjList[v].append(u)  # For an undirected graph

    def DFS(self, v, visited):
        visited[v] = True
        for u in self.adjList[v]:
            if not visited[u]:
                self.DFS(u, visited)

    def isConnected(self):
        visited = [False] * self.V
        startVertex = 0  # Starting vertex for DFS
        self.DFS(startVertex, visited)

        return all(visited)
