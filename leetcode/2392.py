class Solution:
  def kahns(self, n:int, edges:List[List[int]]) -> List[int]:
    indegree = [0 for _ in range(n)]
    adj = [[] for _ in range(n)]
    for edge in edges:
      [u, v] = edge
      adj[u-1].append(v-1)
      indegree[v-1] += 1
    top = []
    starts = deque([i for i,x in enumerate(indegree) if x == 0])
    while starts:
      u = starts.popleft()
      top.append(u+1)
      for v in adj[u]:
        indegree[v] -= 1
        if indegree[v] == 0:
          starts.append(v)
    return [] if sum(indegree) > 0 else top
  def buildMatrix(
    self, k:int,
    rowConditions:List[List[int]], colConditions:List[List[int]]
  ) -> List[List[int]]:
    rowSorted = self.kahns(k, rowConditions)
    colSorted = self.kahns(k, colConditions)
    if not len(rowSorted) or not len(colSorted):
      return []
    rowSorted = {x:i for i,x in enumerate(rowSorted)}
    colSorted = {x:i for i,x in enumerate(colSorted)}
    matrix = [[0 for _ in range(k)] for _ in range(k)]
    for x in range(k):
      i = rowSorted[x+1]
      j = colSorted[x+1]
      matrix[i][j] = x+1
    return matrix

