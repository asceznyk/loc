class Solution:
  def longestStrChain(self, words:List[str]) -> int:
    def isSubseq(a:str, b:str) -> bool:
      for i in range(len(b)):
        w = b[:i] + b[(i+1):]
        if w == a: return True
      return False
    @cache
    def dfs(i:int) -> int:
      maxLen = 1
      for j in range(i):
        word, size = pairs[j]
        if size+1 == pairs[i][1] and isSubseq(word, pairs[i][0]):
          maxLen = max(1+dfs(j), maxLen)
      return maxLen
    pairs = [(w,len(w)) for w in words]
    pairs = sorted(pairs, key = lambda x: x[1])
    n = len(words)
    ans = 1
    for i in range(n-1, -1, -1):
      ans = max(ans, dfs(i))
    return ans

