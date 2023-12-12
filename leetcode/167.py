from typing import List

INF = 10000
class Solution:
  def twoSum(self, numbers:List[int], target:int) -> List[int]:
    rp = 0
    lp = len(numbers)-1
    diff = INF
    while abs(diff):
      diff = (numbers[rp] + numbers[lp]) - target
      if diff > 0: lp -= 1
      if diff < 0: rp += 1
    return [rp+1, lp+1]

