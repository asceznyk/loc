class Solution:
  def numSmallerByFrequency(self, queries:List[str], words:List[str]) -> List[int]:
    fQueries, fWords = [], []
    for x in queries:
      minC = 27
      cnt = {}
      for c in x:
        idx = ord(c)-ord('a')
        minC = min(idx, minC)
        if cnt.get(idx) is None: cnt[idx] = 0
        cnt[idx] += 1
      fQueries.append(cnt[minC])
    for x in words:
      minC = 27
      cnt = {}
      for c in x:
        idx = ord(c)-ord('a')
        minC = min(idx, minC)
        if cnt.get(idx) is None: cnt[idx] = 0
        cnt[idx] += 1
      fWords.append(cnt[minC])
    res = [0 for _ in range(len(fQueries))]
    for i, fQ in enumerate(fQueries):
      for fW in fWords:
        if fQ >= fW: continue
        res[i] += 1
    return res


