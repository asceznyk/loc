from typing import List

class Solution:
  def twoSum(self, numbers:List[int], target:int) -> List[int]:
    l, r = 0, len(numbers)-1
    while (l < r):
      l, r = numbers[l], numbers[r]
      if l+r == target: return [l+1, r+1]
      elif l+r > target: r -= 1
      else: l += 1
    return [0]

