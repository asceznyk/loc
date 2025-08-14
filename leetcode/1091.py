class Solution:
  def shortestPathBinaryMatrix(self, grid:List[List[int]]) -> int:
    INF = 10**9
    n = len(grid)
    if grid[0][0] == 1 or grid[n-1][n-1] == 1:
      return -1
    score = [[INF for _ in range(n)] for _ in range(n)]
    score[0][0] = 1
    heap = [(score[0][0], 0, 0)]
    heapq.heapify(heap)
    while len(heap):
      mScore, i, j = heappop(heap)
      for (dx,dy) in [(0,1),(0,-1),(1,0),(-1,0),(1,1),(1,-1),(-1,1),(-1,-1)]:
        di, dj = i+dx, j+dy
        if di < 0 or di > n-1 or dj < 0 or dj > n-1 or\
            score[di][dj] != INF or grid[di][dj] == 1:
          continue
        if 1+mScore < score[di][dj]:
          score[di][dj] = 1+mScore
          heappush(heap, (score[di][dj], di, dj))
    return score[n-1][n-1] if score[n-1][n-1] != INF else -1

