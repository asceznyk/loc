class Solution:
  def leastBricks(self, wall:List[List[int]]) -> int:
    rows = len(wall)
    colSum = sum(wall[0])
    gapCount = {colSum:0}
    for i in range(len(wall)):
      pSum = 0
      for v in wall[i]:
        pSum += v
        if pSum == colSum: continue
        if not gapCount.get(pSum, 0): gapCount[pSum] = 1
        else: gapCount[pSum] += 1
    return min(rows, rows-max(gapCount.values()))

