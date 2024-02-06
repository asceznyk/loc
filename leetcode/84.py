from typing import List

class Solution:
  def largestRectangleArea(self, heights:List[int]) -> int:
    maxArea = 0
    stack = []
    for i, h in enumerate(heights):
      p = i
      while stack and stack[-1][0] > h:
        g, j = stack.pop()
        p = j
        maxArea = max(maxArea, g, h*(i-j+1), g*(i-j))
      stack.append((h,p))
    n = len(heights)
    for h, i in stack:
      maxArea = max(maxArea, h*(n-i))
    return maxArea

