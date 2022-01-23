from sys import stdin, stdout

class Edge:
    def __init__(self, f_id, t_id, score):
        self.f_id = f_id
        self.t_id = t_id
        self.score = score

def graph(vertices, edges, descs):
    graph = []
    for e in range(edges):
        graph.append(Edge(*descs[e]))

    return graph

def read_input():
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

#def span_trees(graph):

#def min_ority(graph): 

graphs = read_input()


