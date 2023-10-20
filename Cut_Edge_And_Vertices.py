class Graph:
    def __init__(self, V):
        self.V = V
        self.adjList = [[] for _ in range(V)]
        self.discoveryTime = [-1] * V
        self.lowTime = [-1] * V
        self.parent = [-1] * V
        self.isCutVertex = [False] * V
        self.cutEdges = []
        self.time = 0

    def add_edge(self, u, v):
        self.adjList[u - 1].append(v)
        self.adjList[v - 1].append(u)

    def find_cut_vertices(self, u):
        children = 0
        self.discoveryTime[u - 1] = self.lowTime[u - 1] = self.time
        self.time += 1

        for v in self.adjList[u - 1]:
            if self.discoveryTime[v - 1] == -1:
                children += 1
                self.parent[v - 1] = u
                self.find_cut_vertices(v)
                self.lowTime[u - 1] = min(self.lowTime[u - 1], self.lowTime[v - 1])
                if self.lowTime[v - 1] >= self.discoveryTime[u - 1] and self.parent[u - 1] != -1:
                    self.isCutVertex[u - 1] = True
                if self.lowTime[v - 1] > self.discoveryTime[u - 1]:
                    self.cutEdges.append((u, v))
            elif v != self.parent[u - 1]:
                self.lowTime[u - 1] = min(self.lowTime[u - 1], self.discoveryTime[v - 1])

        if self.parent[u - 1] == -1 and children > 1:
            self.isCutVertex[u - 1] = True

if __name__ == "__main__":
    V = int(input("Enter the number of vertices: "))
    graph = Graph(V)

    E = int(input("Enter the number of edges: "))

    for i in range(E):
        u, v = map(int, input(f"Enter edge {i + 1} (source destination): ").split())
        graph.add_edge(u, v)

    for i in range(V):
        graph.discoveryTime[i] = -1
        graph.lowTime[i] = -1
        graph.parent[i] = -1

    for i in range(1, V + 1):
        if graph.discoveryTime[i - 1] == -1:
            graph.find_cut_vertices(i)

    print("Cut Vertices: ", end="")
    for i in range(V):
        if graph.isCutVertex[i]:
            print(i + 1, end=" ")

    print("\nCut Edges:", end=" ")
    for u, v in graph.cutEdges:
        print(f"({u}, {v})", end=" ")
    print()
