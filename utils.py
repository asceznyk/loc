from sys import stdin, stdout

def graph(descs):
    graph = 
    for d in descs:
        [v, i, s] = d
        graph[v] = {} if v not in graph else graph[v]
        graph[v][i] = s

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
        graphs.append(graph(descs))
        _ = std_line()

    return graphs


