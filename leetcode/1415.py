class Solution:
  def getHappyString(self, n:int, k:int) -> str:
    happy = "abc"
    m = 0
    ans = ""
    def dfs(s:str, d:int):
      nonlocal m, ans
      if d == n:
        m += 1
        if m == k: ans = s
        return
      for x in happy:
        if x == s[-1]: continue
        dfs(s+x, d+1)
    for x in happy: dfs(x, 1)
    return ans

