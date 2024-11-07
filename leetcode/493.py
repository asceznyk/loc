from sortedcontainers import SortedList

class Solution:
  def reversePairs(self, nums:List[int]) -> int:
    oset = SortedList([])
    ans = 0
    for x in nums:
      l = len(oset)
      i = oset.bisect_right(2*x)
      ans += (l-i) if l >= i else 0
      oset.add(x)
    return ans
