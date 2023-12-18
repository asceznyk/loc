from typing import List

class Solution:
  def dailyTemperatures(self, temperatures:List[int]) -> List[int]:
    stack = []
    days = [0 for t in temperatures]
    for i, t in enumerate(temperatures):
      if i > 0 and t > p:
        while stack:
          j, k = stack.pop()
          days[j] = i-j
          if k >= t:
            stack.append((j,k))
            days[j] = 0
            break
      stack.append((i,t))
      p = t
    return days


