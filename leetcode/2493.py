class Solution:
  INF = 10**9
  def bipartite(self, graph:List[List[int]]) -> bool:
    def dfs(graph:List[List[int]], u:int, b:int):
      if visited[u] != -1:
        visited[u] = 2 if visited[u] != b else visited[u]
        return
      visited[u] = b
      for v in graph[u]: dfs(graph, v, 1^b)
    n = len(graph)
    if n == 1: return True
    visited = [-1 for _ in range(n)]
    for u in range(n):
      if visited[u] != -1:
        if visited[u] == 2: return False
      dfs(graph, u, 0)
    return True
  def magnificentSets(self, n:int, edges:List[List[int]]) -> int:
    def countGrps(r:int, dist:List[int], record:bool):
      dist[r] = 1
      heap = [(dist[r],r)]
      while len(heap):
        d, u = heappop(heap)
        if visited[u]: continue
        visited[u] = 1
        if record: nodes.append(u)
        for v in graph[u]:
          if 1+d < dist[v]:
            dist[v] = 1+d
            heappush(heap, (1+d,v))
    graph = [[] for _ in range(n)]
    for a,b in edges:
      graph[a-1].append(b-1)
      graph[b-1].append(a-1)
    if not self.bipartite(graph):
      return -1
    ans = 0
    visited = [0 for _ in range(n)]
    dist = [self.INF for _ in range(n)]
    for u in range(n):
      if visited[u]: continue
      grps = 1
      nodes = []
      countGrps(u, dist, record=True)
      for v in nodes:
        for x in nodes:
          visited[x] = 0
          dist[x] = self.INF
        countGrps(v, dist, record=False)
        for x in nodes: grps = max(dist[x], grps)
      ans += grps
    return ans


