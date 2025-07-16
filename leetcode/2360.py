class Solution:
  def longestCycle(self, edges:List[int]) -> int:
    def dfs(i:int, t:int) -> int:
      if i == -1: return -1
      if disc[i] > 0: 
        return t-disc[i]
      disc[i] = t
      r = dfs(edges[i], t+1)
      disc[i] = (r if r > 0 else -1)
      return disc[i] 
    disc = [-1 for _ in range(len(edges))]
    ans = -1
    for i in range(len(edges)):
      r = dfs(i, 0)
      ans = max(ans, r)
    return ans

