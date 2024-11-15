
class Solution:
  def isSubsequence(self, s:str, t:str) -> bool:
    if len(s) == 0:
      return True
    if len(t) == 0:
      return False
    k = 0
    e = s[k]
    for c in t:
      if c == e:
        k += 1
        e = s[k] if k < len(s) else ""
    return k == len(s) 

