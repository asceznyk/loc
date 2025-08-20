class Solution:
  def maximumInvitations(self, favorite:List[int]) -> int:
    def getCycle(u:int):
      visited[u] = 1
      v = favorite[u]
      parentMap[v] = u
      if not visited[v]:
        getCycle(v)
      else:
        if cycleHeadLen.get(v,0): return
        if nonNodes.get(v,0): return
        x = u
        cycle = [v]
        while x != v and x != -1:
          cycle.append(x)
          x = parentMap[x]
        if x == -1:
          for x in cycle: nonNodes[x] = 1
        else:
          for x in cycle:
            cycleNodes[x] = 1
            cycleHeadLen[x] = len(cycle)
          if len(cycle) == 2:
            [a,b] = cycle
            if a > b: a,b = b,a
            twoCycles[a] = b
    def expandSource(u:int) -> int:
      if cycleNodes.get(u) or u == -1: return 0
      if dp[u] != 0: return dp[u]
      d = 1
      for v in reverseMap.get(u,[]): d = max(d, 1+expandSource(v))
      dp[u] = d
      return dp[u]
    n = len(favorite)
    visited = [0 for _ in range(n)]
    reverseMap = {}
    for i, x in enumerate(favorite):
      if not reverseMap.get(x): reverseMap[x] = []
      reverseMap[x].append(i)
    cycleNodes, nonNodes = {}, {}
    parentMap, twoCycles, cycleHeadLen = [-1 for _ in range(n)], {}, {}
    for i in range(n): getCycle(i)
    ans, twoCnt = 2, 0
    dp = [0 for _ in range(n)]
    for head, size in cycleHeadLen.items(): ans = max(ans, size)
    for x, y in twoCycles.items():
      cycleNodes[x] = 0
      expX = expandSource(x)
      cycleNodes[x] = 1
      cycleNodes[y] = 0
      expY = expandSource(y)
      cycleNodes[y] = 1
      twoCnt += expX+expY
    return max(twoCnt, ans)

