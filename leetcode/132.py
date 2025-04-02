class Solution:
  def minCut(self, s:str) -> int:
    n = len(s)
    isPal = [[0 for _ in range(n)] for _ in range(n)]
    dp = [[-1 for _ in range(n+1)] for _ in range(n+1)]
    def expandFromMiddle(l:int, r:int):
      while (l >= 0 and r < n and s[l] == s[r]):
        isPal[l][r] = 1
        l -= 1
        r += 1
    for i in range(n):
      expandFromMiddle(i,i)
      expandFromMiddle(i,i+1)
      expandFromMiddle(i-1,i)
    def dfs(i:int, p:int) -> int:
      if i == n-1:
        return 0 if isPal[p][n-1] else n-1
      if dp[i][p] != -1:
        return dp[i][p]
      if isPal[p][n-1]:
        dp[i][p] = 0
        return dp[i][p]
      if not isPal[p][i]:
        dp[i][p] = dfs(i+1, p)
        return dp[i][p]
      dp[i][p] = min(1+dfs(i+1, i+1), dfs(i+1, p))
      return dp[i][p]
    ans = dfs(0, 0)
    return ans


