from typing import List

class Solution:
  def maxSubArray(self, nums: List[int]) -> int:
    m, s = -10001, 0
    for n in nums:
      s = max(s+n, n)
      m = max(m, s)
    return m


