from typing import List

class Solution:
  def search(self, nums:List[int], target:int) -> int:
    lp = 0
    rp = len(nums)-1
    while lp <= rp:
      mp = (rp+lp)//2
      n = nums[mp]
      if n == target: return mp
      if n < target: lp = mp+1
      elif n > target: rp = mp-1
    return -1

