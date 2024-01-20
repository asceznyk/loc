from typing import List

class Solution:
  def maxAreaOfIsland(self, grid:List[List[str]]) -> int:
    def dfsTree(y:int, x:int):
      if (
        (not (0<=y<m)) or (not (0<=x<n))
        or (grid[y][x] != 1) or f"{y}_{x}" in seen
      ): return 0
      seen.add(f"{y}_{x}")
      return (
        1 + dfsTree(y,x+1) + dfsTree(y+1,x)
        + dfsTree(y,x-1) + dfsTree(y-1,x)
      )
    k = 0
    seen = set()
    m, n = len(grid), len(grid[0])
    for i in range(m):
      for j in range(n):
        if grid[i][j] != 1: continue
        k = max(k, dfsTree(i, j))
    return k

