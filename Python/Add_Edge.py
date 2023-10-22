def add_edge(src, dest):
    adj_list[src - 1].append(dest)
    adj_list[dest - 1].append(src)
