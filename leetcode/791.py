class Solution:
  def customSortString(self, order:str, s:str) -> str:
    freq = {}
    v = ""
    for c in s:
      if c in order:
        if not freq.get(c): freq[c] = 0
        freq[c] += 1
      else:
        v += c
    u = ""
    for c in order:
      if freq.get(c,0):
        u += c*(freq[c])
    return u+v


