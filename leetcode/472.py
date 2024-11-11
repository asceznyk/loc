class Solution:
  def findAllConcatenatedWordsInADict(self, words:List[str]) -> List[str]:
    dp = {}
    wordSet = set(words)
    def dfs(word:str) -> bool:
      if word in dp:
        return dp[word]
      for i in range(1, len(word)):
        prefix = word[:i]
        suffix = word[i:]
        if prefix in wordSet and (suffix in wordSet or dfs(suffix)):
          dp[word] = True
          return dp[word]
      dp[word] = False
      return dp[word]
    res = []
    for w in words:
      if dfs(w):
        res.append(w)
    return res


