class Solution:
  def trapRainWater(self, heightMap:List[List[int]]) -> int:
    m, n = len(heightMap), len(heightMap[0])
    bMap = deepcopy(heightMap)
    if m < 3 or n < 3: return 0
    inBoundary = []
    for j in range(n):
      heappush(inBoundary, (heightMap[0][j], 0, j))
      heappush(inBoundary, (heightMap[m-1][j], m-1, j))
    for i in range(1, m-1):
      heappush(inBoundary, (heightMap[i][0], i, 0))
      heappush(inBoundary, (heightMap[i][n-1], i, n-1))
    visited = [[0 for _ in range(n)] for _ in range(m)]
    ans = 0
    while len(inBoundary):
      u, i, j = heappop(inBoundary)
      if visited[i][j]: continue
      visited[i][j] = 1
      for di, dj in [(-1,0),(1,0),(0,-1),(0,1)]:
        fi, fj = i+di, j+dj
        if fi < 0 or fi > m-1 or fj < 0 or fj > n-1 or visited[fi][fj]: continue
        v = bMap[fi][fj]
        if v <= u:
          ans += u-v
          bMap[fi][fj] = u
          heappush(inBoundary, (u, fi, fj))
        else: heappush(inBoundary, (v, fi, fj))
    return ans


