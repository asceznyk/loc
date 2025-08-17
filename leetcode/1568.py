class Solution:
  dirs = [(0,-1),(0,1),(-1,0),(1,0)]
  def numIslands(self, grid:List[List[int]]) -> int:
    def dfsTree(y:int, x:int):
      if (not (0<=y< m)) or (not (0<=x<n)) or (grid[y][x] != 1) or self.visited[y][x]:
        return
      self.visited[y][x] = 1
      for (dy,dx) in self.dirs:
        fy, fx = y+dy, x+dx
        dfsTree(fy, fx)
    c = 0
    m, n = len(grid), len(grid[0])
    for i in range(m):
      for j in range(n):
        if grid[i][j] == 0 or self.visited[i][j]: continue
        dfsTree(i, j)
        c += 1
    for i in range(m):
      for j in range(n):
        self.visited[i][j] = 0
    return c
  def minDays(self, grid:List[List[int]]) -> int:
    m, n = len(grid), len(grid[0])
    self.visited = [[0 for _ in range(n)] for _ in range(m)]
    cnt = self.numIslands(grid)
    if cnt > 1 or cnt == 0: return 0
    for i in range(m):
      for j in range (n):
        if grid[i][j] == 0: continue
        grid[i][j] = 0
        cnt = self.numIslands(grid)
        grid[i][j] = 1
        if cnt > 1 or cnt == 0: return 1
    return 2


