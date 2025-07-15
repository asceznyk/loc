class Solution:
  def minDistance(self, word1:str, word2:str) -> int:
    @cache
    def step(i:int, j:int) -> int:
      if i < 0 or j < 0: return 0
      if word1[i] == word2[j]: return 1+step(i-1, j-1)
      return max(step(i, j-1), step(i-1, j))
    m, n = len(word1), len(word2)
    lcs = step(m-1, n-1)
    return (m-lcs) + (n-lcs)


