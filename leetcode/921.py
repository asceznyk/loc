class Solution:
  def minAddToMakeValid(self, s:str) -> int:
    ans = 0
    stack = []
    for c in s:
      if c == '(':
        stack.append(c)
        continue
      valid = 0
      if stack and stack[-1] == '(':
        valid = 1
        stack.pop()
      if not valid:
        stack.append(c)
    return len(stack)

