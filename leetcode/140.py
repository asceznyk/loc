class Solution:
  def wordBreak(self, s:str, wordDict:List[str]) -> List[str]:
    def backtrack(i:int):
      if i == len(s):
        res.append(" ".join(curr))
        return
      for j in range(i, len(s)):
        word = s[i:j+1]
        if word in wordDict:
          curr.append(word)
          backtrack(j+1)
          curr.pop()
    res = []
    curr = []
    wordDict = set(wordDict)
    backtrack(0)
    return res


