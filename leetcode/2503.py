class Solution:
  def maxPoints(self, grid:List[List[int]], queries:List[int]) -> List[int]:
    k, m, n = len(queries), len(grid), len(grid[0])
    queries = sorted([(q,i) for i, q in enumerate(queries)], key=lambda x: x[0])
    minHeap = []
    heappush(minHeap, (grid[0][0], 0, 0))
    visited = [[0 for _ in range(n)] for _ in range(m)]
    p, cnt = 0, 0
    points = [0 for _ in range(k)]
    while minHeap and p < k:
      curr, i, j = heappop(minHeap)
      if visited[i][j]: continue
      points[p] = cnt
      while p < k and curr >= queries[p][0]:
        points[p] = cnt
        p += 1
      visited[i][j] = 1
      cnt += 1
      for di, dj in [(i+1,j), (i-1,j), (i,j+1), (i,j-1)]:
        if (di < 0 or di > m-1 or dj < 0 or dj > n-1): continue
        heappush(minHeap, (grid[di][dj], di, dj))
    while p < k:
      points[p] = cnt
      p += 1
    res = [0 for _ in range(k)]
    j = 0
    for _, i in queries:
      res[i] = points[j]
      j += 1
    return res


