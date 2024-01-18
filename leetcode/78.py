from typing import List

class Solution:
  def subsets(self, nums:List[int]) -> List[List[int]]:
    def backtrack(k:int, n:int):
      if k == n:
        pos.append(ss.copy())
        return
      backtrack(k+1, n)
      ss.append(nums[k])
      backtrack(k+1, n)
      ss.pop()
    ss = []
    pos = []
    backtrack(0, len(nums))
    return pos

