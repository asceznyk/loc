from utils import *

# O(n*log(n))
class Solution:
  def isNStraightHand(self, hand:List[int], groupSize:int) -> bool:
    if len(hand) % groupSize: return False
    count = {}
    for c in sorted(hand):
      count[c] = 1 + count.get(c,0)
    while len(count):
      s = next(iter(count))
      for _ in range(groupSize):
        if not count.get(s): return False
        count[s] -= 1
        if count[s] == 0: del count[s]
        s += 1
    return True

# O(n)
class Solution:
  def isNStraightHand(self, hand:List[int], groupSize:int) -> bool:
    if len(hand) % groupSize: return False
    count = {}
    for c in hand:
      count[c] = 1 + count.get(c,0)
    minC = list(count.keys())
    heapq.heapify(minC)
    while minC:
      s = minC[0]
      for _ in range(groupSize):
        if not count.get(s): return False
        count[s] -= 1
        if count[s] == 0: heapq.heappop(minC)
        s += 1
    return True
