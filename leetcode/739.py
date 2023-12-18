from typing import List

class Solution:
  def dailyTemperatures(self, temperatures:List[int]) -> List[int]:
    stack = []
    days = [0] * len(temperatures)
    for i, t in enumerate(temperatures):
      while stack and t > stack[-1][1]:
        j, k = stack.pop()
        days[j] = i-j
      stack.append((i,t))
    return days

