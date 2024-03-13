class Solution:
  def partitionLabels(self, s:str) -> List[int]:
    startEnd = {}
    for i, c in enumerate(s):
      if not startEnd.get(c): startEnd[c] = [i,i]
      startEnd[c][1] = i
    lol = []
    for i, (k, v) in enumerate(startEnd.items()):
      if i == 0:
        [start,end] = v
        continue
      [l,r] = v
      if l < end < r or start < r < end:
        start = min(l,start)
        end = max(r,end)
      else:
        lol.append(end-start+1)
        start,end = l,r
    lol.append(end-start+1)
    return lol
