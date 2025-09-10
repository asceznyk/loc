class Solution:
  def stringMatching(self, words:List[str]) -> List[str]:
    res = set()
    n = len(words)
    for i in range(n):
      for j in range(n):
        if i == j: continue
        if words[i] in words[j]:
          res.add(words[i])
    return list(res)
      

