class Solution:
  def isScramble(self, s1:str, s2:str) -> bool:
    smap = {}
    def dfs(x1:str, x2:str) -> bool:
      n = len(x1)
      if x1 == x2: return True
      if n == 1: return False
      key = x1+","+x2
      if smap.get(key) is not None: return smap[key]
      smap[key] = False
      for k in range(1, n):
        if dfs(x1[:k], x2[:k]) and dfs(x1[k:], x2[k:]):
          smap[key] = True
          return smap[key] 
        if dfs(x1[:k], x2[(n-k):]) and dfs(x1[k:], x2[:(n-k)]):
          smap[key] = True
          return smap[key]
      return smap[key]
    return dfs(s1, s2)



