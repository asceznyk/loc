class Solution:
  MOD = (10**9)+7
  def numWays(self, steps:int, arrLen:int) -> int:
    @cache
    def dfs(i:int, s:int) -> int:
      if s == 0 and i == 0: return 1
      if s == 0: return 0
      right = dfs(i+1, s-1) if i < arrLen-1 else 0
      left =  dfs(i-1, s-1) if i > 0 else 0
      return (dfs(i, s-1) + right + left) % self.MOD
    return dfs(0, steps)


