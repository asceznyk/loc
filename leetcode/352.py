class SummaryRanges:
  INF = 1e9+7
  def __init__(self):
    self.numSet = set()
  def addNum(self, value:int):
    self.numSet.add(value)
  def getIntervals(self) -> List[List[int]]:
    nums = sorted(list(self.numSet))
    p = -self.INF
    res = []
    i = -1
    for x in nums:
      if x != p+1:
        res.append([x,x])
        i += 1
      else:
        res[i][1] = x
      p = x
    return res

