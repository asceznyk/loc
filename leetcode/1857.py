class Solution:
  def largestPathValue(self, colors:str, edges:List[List[int]]) -> int:
    def dfs(i:int, c:str) -> int:
      if len(adjList[i]) <= 0:
        dp[i][c] = (1 if (i,c) in exists else 0)
        return dp[i][c]
      if dp[i][c] != 0: return dp[i][c]
      maxCnt = 0
      for j in adjList[i]:
        maxCnt = max(maxCnt, (1 if (i,c) in exists else 0) + dfs(j, c))
      dp[i][c] = maxCnt
      return maxCnt
    n = len(colors)
    indegree = [0 for _ in range(n)]
    adjList = [[] for _ in range(n)]
    alphabet = set([c for c in colors]) 
    for edge in edges:
      [a,b] = edge
      indegree[b] += 1
      adjList[a].append(b)
    roots = [i for i,x in enumerate(indegree) if x == 0]
    qnodes = deque(roots)
    elems = []
    while qnodes:
      node = qnodes.popleft()
      elems.append(node)
      for child in adjList[node]:
        indegree[child] -= 1
        if indegree[child] == 0:
          qnodes.append(child)
    ans = -1
    if sum(indegree) > 0:
      return ans
    dp = [{c:0 for c in alphabet} for _ in range(n)]
    exists = set()
    for i, c in enumerate(colors): exists.add((i,c))
    for c in alphabet:
      for root in roots:
        ans = max(ans, dfs(root, c))
    return ans

