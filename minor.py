from sys import stdin, stdout

inf = 1e9
n, cur = (0, 0)
graph = []

def dfs(v, visited):
    visited[v] = 1
    for u, w in graph[v]:
        if not visited[u] and ((cur | w) == cur):
            dfs(u, visited)

def reduce_ans(p):
    global cur
    if p < 0: return
    d = 1 << p
    cur -= d
    visited = {v:0 for v in range(n)}
    dfs(0, visited)
    for _, v in visited.items():
        if not v:
            cur += d
            break
    reduce_ans(p-1)

def solve():
    global cur
    cur = 1
    bit = 0
    while(cur < inf):
        bit += 1
        cur = cur * 2 + 1
    reduce_ans(bit)
    stdout.write(f"{cur} \n")

def build_graph(v, e, descs):
    c_graph = [[] for _ in range(v)]
    for [u, v, w] in descs:
        u -= 1
        v -= 1
        c_graph[u].append((v, w))
        c_graph[v].append((u, w))
    return c_graph    

def main():
    global n, graph
    def std_line(): return stdin.readline().lstrip().rstrip()

    t = int(std_line())
    _ = std_line()

    stdout.write("\n")
     
    for _ in range(t):
        descs = []
        n, m = [int(x) for x in std_line().split()] 
        for i in range(m):
            descs.append([int(x) for x in std_line().split()]) 
        graph = build_graph(n, m, descs)
        solve()
        _ = std_line()

if __name__ == '__main__':
    main()

