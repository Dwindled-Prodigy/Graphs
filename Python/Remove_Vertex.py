def remove_vertex(vertex):
    if vertex < 1 or vertex > V[0]:
        print("Invalid vertex to remove.")
        return

    # Remove all edges associated with the vertex
    for v in range(1, V[0] + 1):
        if v == vertex:
            continue
        adj_list[v - 1] = [vtx for vtx in adj_list[v - 1] if vtx != vertex]

    # Remove the adjacency list of the removed vertex
    adj_list.pop(vertex - 1)

    # Shift vertices to fill the gap
    for v in range(vertex - 1, V[0] - 1):
        adj_list[v] = adj_list[v + 1]

    # Reduce the number of vertices
    V[0] -= 1
