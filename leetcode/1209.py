class Solution:
  def removeDuplicates(self, s:str, k:int) -> str:
    stack = []
    for c in s:
      if not len(stack) or c != stack[-1][-1]:
        stack.append(c)
        continue
      stack[-1] += c
      if len(stack[-1]) == k: stack.pop()
    return "".join(stack)


