class Graph:
    def __init__(self, V):
        self.V = V
        self.adjList = [[] for _ in range(V)]

    def addEdge(self, u, v):
        self.adjList[u].append(v)

    def topologicalSortUtil(self, v, visited, stack):
        visited[v] = True

        for u in self.adjList[v]:
            if not visited[u]:
                self.topologicalSortUtil(u, visited, stack)

        stack.append(v)

    def topologicalSort(self):
        stack = []
        visited = [False] * self.V

        for i in range(self.V):
            if not visited[i]:
                self.topologicalSortUtil(i, visited, stack)

        while stack:
            print(stack.pop(), end=" ")

# Example usage
V = 6  # Change as needed
graph = Graph(V)

# Add edges (u, v) here
edges = [(5, 2), (5, 0), (4, 0), (4, 1), (2, 3), (3, 1)]  # Change as needed

for u, v in edges:
    graph.addEdge(u, v)

print("Topological Sorting:", end=" ")
graph.topologicalSort()
