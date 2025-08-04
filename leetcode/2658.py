class Solution:
  def findMaxFish(self, grid:List[List[int]]) -> int:
    def dfs(i:int, j:int) -> int:
      if i >= m or i < 0 or j >= n or j < 0 or visited[i][j] != 0 or grid[i][j] == 0:
        return 0
      visited[i][j] = 1
      numFish = grid[i][j]
      for (x,y) in [(i,j+1), (i,j-1), (i+1,j), (i-1,j)]:
        numFish += dfs(x, y)
      return numFish
    m, n = len(grid), len(grid[0])
    visited = [[0 for _ in range(n)] for _ in range(m)]
    ans = 0
    for i in range(m):
      for j in range(n):
        if grid[i][j] == 0 or visited[i][j]: continue
        area = dfs(i,j)
        ans = max(ans, area)
    return ans

