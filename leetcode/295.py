class MedianFinder:

  def __init__(self):
    self.n = 0
    self.minH, self.maxH = [], []

  def balanceHeaps(self):
    maxLen, minLen = len(self.maxH), len(self.minH)
    if abs(minLen - maxLen) <= 1:
      return
    if maxLen >= minLen:
      val = -heappop(self.maxH)
      heappush(self.minH, val)
    else:
      val = heappop(self.minH)
      heappush(self.maxH, -val)

  def addNum(self, num:int):
    self.n += 1
    if len(self.maxH) <= 0:
      heappush(self.maxH, -num)
      return
    if -self.maxH[0] < num:
      heappush(self.minH, num)
    else:
      heappush(self.maxH, -num)
    print("before balacing", self.minH, self.maxH)
    self.balanceHeaps()
    print("after balacing", self.minH, self.maxH)

  def findMedian(self) -> float:
    if self.n % 2:
      return self.minH[0] if (len(self.minH) >= len(self.maxH)) else -self.maxH[0]
    else:
      return (-self.maxH[0] + self.minH[0]) / 2.0


