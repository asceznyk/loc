class Solution:
  def findBiconnectedComponents(self, graph:List[List[int]]) -> List[List[int]]: 
    def dfs(u, parent):
      nonlocal time
      disc[u] = low[u] = time
      time += 1
      children = 0
      for v in graph[u]:
        if v == parent: continue
        if disc[v] == -1: 
          children += 1
          dfs(v, u)
          low[u] = min(low[u], low[v])
          if (low[v] > disc[u]): edges.append([u,v])
          continue
        low[u] = min(low[u], disc[v])
    n = len(graph)
    disc = [-1] * n
    low = [-1] * n
    time = 0
    edges = []
    for u in range(n):
      if disc[u] == -1: dfs(u, -1)
    return edges
  def criticalConnections(self, n:int, connections: List[List[int]]) -> List[List[int]]:
    graph = [[] for _ in range(n)]
    for u,v in connections:
      graph[u].append(v)
      graph[v].append(u)
    return self.findBiconnectedComponents(graph)


