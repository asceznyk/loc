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
      t = -x
      twos = []
      xnums = nums[k+1:]
      lp, rp = 0, len(xnums)-1
      while (lp < rp):
        nl, nr = xnums[lp], xnums[rp]
        if nl+nr == t:
          triplets.add((x, nl, nr))
          lp += 1
          rp -= 1
        elif nl+nr > t: rp -= 1
        else: lp += 1
    return list(triplets)

