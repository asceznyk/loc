class Solution:
  def wordBreak(self, s:str, wordDict:List[str]) -> bool:
    def dfs(i:int) -> int:
      if dp[i] != -1: return dp[i]
      if i == len(s):
        dp[i] = 1
        return dp[i]
      dp[i] = 0
      for w in wordDict:
        k = len(w)
        if w == s[i:i+k]:
          dp[i] |= dfs(i+k)
      return dp[i]
    dp = [-1 for _ in range(len(s)+1)]
    return dfs(0)

class Solution:
  def wordBreak(self, s:str, wordDict:List[str]) -> bool:
    dp = [False for _ in range(len(s)+1)]
    dp[len(s)] = True
    for i in range(len(s)-1, -1, -1):
      for w in wordDict:
        k = len(w)
        if w == s[i:i+k] and i+k <= len(s): dp[i] = dp[i+k]
        if dp[i]: break
    return dp[0]


