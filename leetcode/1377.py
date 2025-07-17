class Solution:
  def frogPosition(self, n:int, edges:List[List[int]], t:int, target:int) -> float:
    def dfs(i:int, d:int) -> float:
      if (i != target and d > 0 and visited[i] != 0) or d < 0: return 0.0
      m = len(adjList[i])
      if i == target:
        if not visited[i] and (d == 0 or (m <= 1 and i != 1)): return 1.0
      visited[i] = 1
      prob = 1/(m if i == 1 else 1 if m == 1 else m-1)
      res = 0.0
      for j in adjList[i]:
        r = dfs(j, d-1)
        res = max(res, r)
      return prob*res
    if n == 1: return 1.0 if target == 1 else 0.0
    adjList = [[] for _ in range(n+1)]
    visited = [0 for _ in range(n+1)]
    for a, b in edges:
      adjList[a].append(b)
      adjList[b].append(a)
    return dfs(1, t)

