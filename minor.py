from sys import stdin, stdout

def std_line(): return stdin.readline().lstrip().rstrip()

infinity = int(1e9)
n, cur = None, None
graph = None

def dfs(v, visited):
    visited[v] = 1
    for (u, w) in graph[v]:
        if not visited[u] and (cur | w) == cur:
            dfs(u, visited)

def reduce_ans(p):
    global cur
    if p < 0: return
    d = 1 << p
    cur -= d
    visited = [0 for v in range(n)]
    dfs(0, visited)
    for v in visited:
        if not v:
            cur += d
            break
    reduce_ans(p-1)

def solve():
    global n, cur, graph
    n, m = [int(x) for x in std_line().split()]
    graph = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = [int(x) for x in std_line().split()]
        u -= 1
        v -= 1
        graph[u].append((v, w))
        graph[v].append((u, w))
    cur = 1
    bit = 0
    while(cur < infinity):
        bit += 1
        cur = cur * 2 + 1
    reduce_ans(bit) 
    stdout.write(f"{cur} \n")

def main():
    t = int(std_line())
    _ = std_line()
    stdout.write("\n")
    for _ in range(t): 
        solve()
        _ = std_line()
    return 0

if __name__ == '__main__':
    main()

