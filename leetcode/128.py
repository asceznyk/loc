from typing import List

INF = (10**9)+5

class Solution:
  def longestConsecutive(self, nums:List[int]) -> int:
    if not len(nums): return 0
    nums = sorted(list(set(nums)))
    counts = []
    c, p = (1, -INF)
    for n in nums:
      if n == p+1:
        c += 1
      else:
        counts.append(c)
        c = 1
      p = n
    counts.append(c)
    return max(counts)


