from typing import List

class Solution:
  def numIslands(self, grid: List[List[str]]) -> int:
    def dfsTree(y:int, x:int):
      if (not (0<=y< m)) or (not (0<=x<n)) or (grid[y][x] != "1"): return
      grid[y][x] = '*'
      for (dy,dx) in dirs:
        fy, fx = y+dy, x+dx
        dfsTree(fy, fx)
    c = 0
    dirs = [(0,-1),(0,1),(-1,0),(1,0)]
    m, n = len(grid), len(grid[0])
    for i in range(m):
      for j in range(n):
        if grid[i][j] != "1": continue
        dfsTree(i, j)
        c += 1
    return c

