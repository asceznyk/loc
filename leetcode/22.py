from typing import List

class Solution:
  def generateParenthesis(self, n:int) -> List[str]:
    patterns = ["()"*n]
    stack = [patterns[0]]
    while stack:
      p = stack.pop()
      for i, c in enumerate(p):
        if i > 0 and f"{p[i-1]}{c}" == ")(":
          np = f"{p[:i-1]}{c}{p[i-1]}{p[i+1:]}"
          if np in patterns: break
          stack.append(np)
          patterns.append(np)
    return patterns
