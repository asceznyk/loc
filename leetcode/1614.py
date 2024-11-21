class Solution:
  def maxDepth(self, s:str) -> int:
    ans, m = 0, 0
    for c in s:
      if c == '(':
        m += 1
      if c == ')':
        m -= 1
      ans = max(m, ans)
    return ans
    
