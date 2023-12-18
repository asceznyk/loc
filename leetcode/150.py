from typing import List
from math import ceil

class Solution:
  def evalRPN(self, tokens:List[str]) -> int:
    ops = '+/*-'
    stack = []
    for t in tokens:
      if t not in ops:
        stack.append(int(t))
        continue
      b = stack.pop()
      a = stack.pop()
      if t == '+': stack.append(a+b)
      elif t == '-': stack.append(a-b)
      elif t == '*': stack.append(a*b)
      else:
        r = int(a/b) if (a<0)^(b<0) else a//b
        stack.append(r)
    return stack.pop()

