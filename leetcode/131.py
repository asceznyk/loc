class Solution:

  def isPalindrome(self, s:str, l:int, r:int) -> bool:
    while l < r:
      if s[l] != s[r]: return False
      l,r = l+1, r-1
    return True

  def partition(self, s:str) -> List[List[str]]:
    def dfs(start:int):
      if start >= len(s):
        res.append(sub.copy())
        return
      for j in range(start, len(s)):
        ss = s[start:j+1]
        if not self.isPalindrome(s, start, j): continue
        sub.append(ss)
        dfs(j+1)
        sub.pop()
    res, sub = [], []
    dfs(0)
    print(res)
    return res
