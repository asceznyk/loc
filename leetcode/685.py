class Solution:
  def findRedundantDirectedConnection(self, edges:List[List[int]]) -> List[int]:
    def getOrbit(curr:int, par:int) -> bool:
      if recStack[curr]: return True
      if visited[curr]: return False
      visited[curr] = 1
      recStack[curr] = 1
      for child in adjList.get(curr, []):
        hasCycle = getOrbit(child, curr)
        if hasCycle:
          cycleEdges.append((curr, child))
          return hasCycle
      recStack[curr] = 0
      return False
    n = len(edges)
    adjInv, adjList = {}, {}
    edgeIdx = {}
    indegree = [0 for _ in range(n+1)]
    for x, edge in enumerate(edges):
      [a,b] = edge
      indegree[b] += 1
      if not adjInv.get(b): adjInv[b] = []
      adjInv[b].append(a)
      if not adjList.get(a): adjList[a] = []
      adjList[a].append(b)
      edgeIdx[(a,b)] = x
    ans, node = [], -1
    for i, degree in enumerate(indegree):
      if i == 0: continue
      if degree <= 1: continue
      node = i
      break
    visited = [0 for _ in range(n+1)]
    recStack = [0 for _ in range(n+1)]
    cycleEdges = []
    isCyclic = False
    if node != -1:
      isCyclic = getOrbit(node, -1)
    else:
      for x in range(1, n+1):
        isCyclic = getOrbit(x, -1)
        if isCyclic: break
    result = []
    if node != -1:
      result = [cycleEdges[0]] if isCyclic else [(j,node) for j in adjInv[i]]
    else: 
      result = cycleEdges
    c = -1
    for (i,j) in result:
      v = edgeIdx[(i,j)]
      if v <= c: continue
      c = v
      ans = [i,j]
    return ans
      
