from sortedcontainers import SortedList

class Solution:
  def countSmaller(self, nums:List[int]) -> List[int]:
    oset = SortedList([])
    res = []
    for x in reversed(nums):
      i = oset.bisect_left(x)
      res.append(i)
      oset.add(x)
    return res[::-1]

    
