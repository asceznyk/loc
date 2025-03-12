class Solution:
  def canSeePersonsCount(self, heights:List[int]) -> List[int]:
    n = len(heights)
    if n <= 2: return [1,0] if n == 2 else [0]
    res = [1 for _ in range(n)]
    res[-1] = 0
    stack = []
    for i in range(n-1, n-3, -1):
      curr = heights[i]
      while len(stack) and (curr > stack[-1]):
        stack.pop()
      stack.append(curr)
    for i in range(n-3, -1, -1):
      curr = heights[i]
      npop = 1
      while len(stack) and (curr > stack[-1]):
        npop += 1 if len(stack) > 1 else 0
        stack.pop()
      res[i] = npop
      stack.append(curr)
    return res


