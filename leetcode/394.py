class Solution:
  def decodeString(self, s:str) -> str:
    k = 0
    d = ""
    numbers = "1234567890"
    stack = []
    while k <= len(s)-1:
      c = s[k]
      if c == "[":
        j = k-1
        while s[j] in numbers: j -= 1
        n = int(s[j+1:k])
        x = ""
        k += 1
        while s[k] not in numbers and s[k] != "]":
          x += s[k]
          k += 1
        stack.append([n, x])
      elif c == "]":
        k += 1
        n, x = stack.pop()
        if not len(stack):
          d += n*x
          continue
        stack[-1][1] += n*x
      else:
        k += 1
        if c in numbers: continue
        if not len(stack):
          d += c
          continue
        stack[-1][1] += c
    return d

