class Solution:
  nodesA, nodesB, nodesC = set(), set(), set()
  def maxNumEdgesToRemove(self, n:int, edges:List[List[int]]) -> int:
    self.nodesA, self.nodesB = 0, 0
    self.compsC = []
    self.idx = 0
    def dfs(u:int, graph:List[List[int]], visited:List[int], utype:int) -> int:
      if visited[u]: return
      visited[u] = 1
      if utype == 1: self.nodesA += 1
      elif utype == 2: self.nodesB += 1
      else: self.compsC[self.idx] += 1
      for v in graph[u]:
        dfs(v, graph, visited, utype)
      return
    graphA = [[] for _ in range(n)]
    graphB = [[] for _ in range(n)]
    graphC = [[] for _ in range(n)]
    e = len(edges)
    startA, startB, pointsC = 0, 0, set()
    for edge in edges:
      [t, u, v] = edge
      if t == 3:
        yesA, yesB = True, True
      else:
        yesA, yesB = (t==1), (t==2)
      if yesA and yesB:
        graphC[u-1].append(v-1)
        graphC[v-1].append(u-1)
        pointsC.add(u-1)
      if yesA:
        graphA[u-1].append(v-1)
        graphA[v-1].append(u-1)
        startA = u-1
      if yesB:
        graphB[u-1].append(v-1)
        graphB[v-1].append(u-1)
        startB = u-1
    dfs(startA, graphA, [0 for _ in range(n)], 1)
    dfs(startB, graphB, [0 for _ in range(n)], 2)
    visitedC = [0 for _ in range(n)]
    for u in pointsC:
      if visitedC[u]: continue
      self.compsC.append(0)
      dfs(u, graphC, visitedC, 3)
      self.idx += 1
    if self.nodesA < n or self.nodesB < n:
      return -1
    ans = 0
    c = sum(self.compsC) - self.idx
    return e - (n-1) if c >= n-1 else e - (2*n-c-2)

