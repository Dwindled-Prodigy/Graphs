class Graph:
    def __init__(self, V):
        self.V = V
        self.adj_list = [[] for _ in range(V)]

    def add_edge(self, src, dest):
        self.adj_list[src - 1].append(dest)
        self.adj_list[dest - 1].append(src)

    def print_graph(self):
        for v in range(1, self.V + 1):
            print(f"Vertex {v}: ", end="")
            for i in range(1, self.V + 1):
                is_neighbor = 1 if i in self.adj_list[v - 1] else 0
                print(f"{is_neighbor} ", end="")
            print()

if __name__ == "__main__":
    V = int(input("Enter the number of vertices: "))
    E = int(input("Enter the number of edges: "))

    graph = Graph(V)

    for _ in range(E):
        src, dest = map(int, input("Enter edge (source destination): ").split())
        graph.add_edge(src, dest)

    graph.print_graph()
