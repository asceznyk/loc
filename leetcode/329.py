class Solution:
  def longestIncreasingPath(self, matrix:List[List[int]]) -> int:
    m, n = len(matrix), len(matrix[0])
    dp = [[1 for _ in range(n)] for _ in range(m)]
    dirs = [(0,1),(0,-1),(1,0),(-1,0)]
    def dfs(i:int, j:int) -> int:
      if dp[i][j] != 1: return dp[i][j]
      lmax = 1
      for di, dj in dirs:
        li, lj = i+di, j+dj
        if li < 0 or li > m-1 or lj < 0 or lj > n-1 or matrix[li][lj] <= matrix[i][j]:
          continue
        lmax = max(lmax, 1+dfs(li, lj))
      dp[i][j] = lmax
      return dp[i][j]
    ans = 1
    for i in range(m):
      for j in range(n):
        ans = max(ans, dfs(i,j))
    return ans


