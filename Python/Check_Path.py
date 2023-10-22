class Graph:
    def __init__(self, V):
        self.V = V
        self.adjList = [[] for _ in range(V)]

    def addEdge(self, u, v):
        self.adjList[u].append(v)
        self.adjList[v].append(u)  # For an undirected graph

    def hasPath(self, src, dest):
        visited = [False] * self.V
        queue = []

        visited[src] = True
        queue.append(src)

        while queue:
            current = queue.pop(0)

            for neighbor in self.adjList[current]:
                if neighbor == dest:
                    return True  # Path found
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append(neighbor)

        return False  # No path found
