class Graph:
    def __init__(self, V):
        self.V = V
        self.adjList = [[] for _ in range(V)]
        self.traversalPath = []

    def addEdge(self, src, dest):
        self.adjList[src - 1].append(dest)
        self.adjList[dest - 1].append(src)  # For undirected graph, add the reverse edge

    def DFS(self, startVertex):
        visited = [False] * self.V
        self.traversalPath.clear()
        self.DFSUtil(startVertex, visited)

    def DFSUtil(self, vertex, visited):
        visited[vertex - 1] = True
        self.traversalPath.append(vertex)

        for adjVertex in self.adjList[vertex - 1]:
            if not visited[adjVertex - 1]:
                self.DFSUtil(adjVertex, visited)

    def printGraph(self):
        for v in range(1, self.V + 1):
            print(f"Vertex {v}: ", end='')
            for i in range(1, self.V + 1):
                isNeighbor = False
                for neighbor in self.adjList[v - 1]:
                    if neighbor == i or v in self.adjList[i - 1]:
                        isNeighbor = True
                        break
                print(f"{int(isNeighbor)} ", end='')
            print()

if __name__ == "__main__":
    V = int(input("Enter the number of vertices: "))
    graph = Graph(V)

    E = int(input("Enter the number of edges: "))

    for i in range(E):
        src, dest = map(int, input("Enter edge (source destination): ").split())
        graph.addEdge(src, dest)

    startVertex = int(input("Starting vertex for DFS: "))
    graph.DFS(startVertex)

    print(f"Depth-First Search (DFS) starting from vertex {startVertex}:")
    print("Traversal path:", " -> ".join(map(str, graph.traversalPath)))

    print("Adjacency Graph:")
    graph.printGraph()
