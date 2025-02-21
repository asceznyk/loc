from sortedcontainers import SortedList

class Solution:
  def reversePairs(self, nums:List[int]) -> int:
    oset = SortedList([])
    ans = 0
    for x in nums:
      ans += (len(oset)-oset.bisect_right(2*x))
      oset.add(x)
    return ans
