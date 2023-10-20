class Graph:
    def __init__(self, V):
        self.V = V
        self.adjList = [[] for _ in range(V)]

    def addEdge(self, u, v):
        self.adjList[u].append(v)

    def hasCycleUtil(self, v, visited, stack):
        visited[v] = True
        stack[v] = True

        for u in self.adjList[v]:
            if not visited[u]:
                if self.hasCycleUtil(u, visited, stack):
                    return True
            elif stack[u]:
                return True  # Cycle detected

        stack[v] = False
        return False

    def hasCycle(self):
        visited = [False] * self.V
        stack = [False] * self.V

        for v in range(self.V):
            if not visited[v]:
                if self.hasCycleUtil(v, visited, stack):
                    return True

        return False
