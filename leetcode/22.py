import time
from typing import List

class Solution:
  def generateParenthesis(self, n:int) -> List[str]:
    def backtrack(nopen, nclose):
      if nopen == nclose == n:
        patterns.append("".join(stack))
        return
      if nopen < n:
        stack.append("(")
        backtrack(nopen+1, nclose)
        stack.pop()
      if nclose < nopen:
        stack.append(")")
        backtrack(nopen, nclose+1)
        stack.pop()
    nopen, nclose = 0, 0
    stack = []
    patterns = []
    backtrack(0,0)
    return patterns

