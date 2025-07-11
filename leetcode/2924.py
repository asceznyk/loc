class Solution:
  def findChampion(self, n:int, edges:List[List[int]]) -> int:
    def dfs(u:int):
      if visited[u]: return
      visited[u] = True
      for v in adjList[u]:
        inDegree[v] += 1
        dfs(v)
    inDegree = [0 for _ in range(n)]
    visited = [False for _ in range(n)]
    adjList = [[] for _ in range(n)]
    for edge in edges:
      [a,b] = edge
      adjList[a].append(b)
    for i in range(n): dfs(i)
    ans, found = -1, False
    for i in range(n):
      if found and inDegree[i] == 0: return -1
      if inDegree[i] == 0:
        ans = i
        found = True
    return ans


