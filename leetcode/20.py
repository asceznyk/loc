class Solution:
  def isValid(self, s:str) -> bool:
    closing = {
      "{":"}",
      "(":")",
      "[":"]"
    }
    stack = []
    l = 0
    for c in s:
      if len(stack) and c == closing[stack[-1]]:
        stack.pop()
        l += 2
      if c in closing: stack.append(c)
    return len(stack) == 0 and len(s) == l

