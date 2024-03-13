from typing import List

class Solution:
  def maxArea(height:List[int]) -> int:
    l = 0
    r = len(height)-1
    mwater = 0
    while(l < r):
      lh, rh = height[l], height[r]
      area = abs(r-l) * min(lh, rh)
      mwater = max(area, mwater)
      if lh <= rh: l += 1
      else: r -= 1
    return mwater

