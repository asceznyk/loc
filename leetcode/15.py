from typing import List

class Solution:
  def threeSum(self, nums:List[int]) -> List[List[int]]:
    triplets = set()
    nums = sorted(nums)
    if all([x > 0 for x in nums]): return list(triplets)
    elif all([x < 0 for x in nums]): return list(triplets)
    for k, x in enumerate(nums):
      if x > 0: break
      if k > 0 and nums[k-1] == x: continue
      xnums = nums[k+1:]
      lp, rp = 0, len(xnums)-1
      while (lp < rp):
        tsum = xnums[lp] + xnums[rp] + x
        if tsum > 0: rp -= 1
        elif tsum < 0: lp += 1
        else:
          triplets.add((x, xnums[lp], xnums[rp]))
          lp += 1
          rp -= 1
    return list(triplets)

