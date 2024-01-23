from typing import List, Tuple
from collections import deque

class Solution:
  def orangesRotting(self, grid:List[List[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    dirs = [(0,1),(1,0),(0,-1),(-1,0)]
    nfresh, rotten = 0, deque()
    for i in range(m):
      for j in range(n):
        if grid[i][j] == 1: nfresh += 1
        if grid[i][j] == 2: rotten.append((i,j))
    minutes = 0
    while rotten and nfresh:
      minutes += 1
      for _ in range(len(rotten)):
        i,j = rotten.popleft()
        for di,dj in dirs:
          fi,fj = i+di,j+dj
          if not (0<=fj<n and 0<=fi<m and grid[fi][fj] == 1): continue
          grid[fi][fj] = 2
          rotten.append((fi,fj))
          nfresh -= 1
    return minutes if nfresh == 0 else -1

