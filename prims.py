from sys import stdin, stdout

def graph(v, e, descs):
    def check_idxs(i,j):
        for [v1, v2, s] in descs:
            if v1 == i and v2 == j:
                return 1
        return 0

    graph = [[0 for _ in range(v)] for _ in range(v)] 
    for [v1, v2, s] in descs:
        graph[v1-1][v2-1] = s
        if not check_idxs(v2, v1):
            graph[v2-1][v1-1] = s

    return graph

def build_graphs():
    def std_line(): return stdin.readline().lstrip().rstrip()

    t = int(std_line())
    _ = std_line()
    graphs = []
     
    for k in range(t):
        descs = []
        n, m = [int(x) for x in std_line().split()] 
        for i in range(m):
            descs.append([int(x) for x in std_line().split()]) 
        graphs.append(graph(n, m, descs))
        _ = std_line()

    return graphs

def prims(graph):
    def min_g():
        min_r = []
        for y, row in enumerate(graph):
            min_v = 30000
            for x, v in enumerate(row):
                if v != 0 and v < min_v:
                    min_v = v
                    min_x = x
            min_r.append((y, min_x, min_v))
        min_v1, min_v2, v = min(min_r, key=lambda t : t[2])
        return min_v1, min_v2

    visited = [] ## a list of vertex indices
    min_v1, min_v2 = min_g()
        

graphs = build_graphs()
for g in graphs:    
    prims(g)

