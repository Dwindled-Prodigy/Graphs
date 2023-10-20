def remove_edge(src, dest):
    if src < 1 or src > V[0] or dest < 1 or dest > V[0]:
        print("Invalid vertices for edge removal.")
        return

    adj_list[src - 1] = [vtx for vtx in adj_list[src - 1] if vtx != dest]
    adj_list[dest - 1] = [vtx for vtx in adj_list[dest - 1] if vtx != src]
}
