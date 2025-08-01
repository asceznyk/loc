class Solution:
  def minimumTime(self, n:int, relations:List[List[int]], time:List[int]) -> int:
    def dfs(i:int) -> int:
      if mem[i] != -1: return mem[i]
      pSum = time[i] 
      for j in adj[i]:
        pSum = max(time[i]+dfs(j), pSum)
      mem[i] = pSum
      return mem[i]
    indegree = [0 for _ in range(n)]
    adj = [[] for _ in range(n)]
    for edge in relations:
      [a,b] = edge
      indegree[b-1] += 1
      adj[a-1].append(b-1)
    nodes = []
    mem = [-1 for _ in range(n+1)]
    ans = 0
    for root in [i for i, v in enumerate(indegree) if v == 0]: ans = max(ans, dfs(root))
    return ans

