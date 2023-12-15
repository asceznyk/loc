from typing import List

class Solution:
  def twoSum(self, numbers:List[int], target:int) -> List[int]:
    lp, rp = 0, len(numbers)-1
    while (lp < rp):
      l, r = numbers[lp], numbers[rp]
      if l+r == target: return [lp+1, rp+1]
      elif l+r > target: rp -= 1
      else: lp += 1
    return [0]

