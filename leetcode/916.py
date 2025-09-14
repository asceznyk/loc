class Solution:
  def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
    def isSubset(uFreq:Dict) -> bool:
      for k in sFreq:
        if not uFreq.get(k,0) or sFreq[k] > uFreq[k]:
          return False
      return True
    res = []
    sFreq = {}
    for word in words2:
      wFreq = {}
      for c in word:
        if not wFreq.get(c,0): wFreq[c] = 0
        wFreq[c] += 1
        if not sFreq.get(c,0): sFreq[c] = 0
        sFreq[c] = max(sFreq[c], wFreq[c])
    for word in words1:
      uFreq = {}
      for c in word:
        if not uFreq.get(c,0): uFreq[c] = 0
        uFreq[c] += 1
      if not isSubset(uFreq): continue
      res.append(word)
    return res

