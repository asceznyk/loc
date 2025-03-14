class Solution:
  def orderlyQueue(self, s:str, k:int) -> str:
    n = len(s)
    ans = s
    if k > 1:
      ans = ''.join([c for c in sorted(s)])
    else:
      curr = s
      for i in range(n):
        curr = curr[1:] + curr[0]
        ans = min(ans, curr)
    return ans 
        
