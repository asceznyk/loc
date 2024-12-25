class Solution:
  
  def combine(self, s1:str, s2:str) -> str: 
    sa, sb = '', ''
    i, j = len(s1)-1, 0
    m = 0
    while i > -1 and j < len(s2):
      sa = s1[i] + sa
      sb += s2[j]
      if sa == sb:
        m = len(sa)
      i -= 1
      j += 1
    return s1 if s2 in s1 else s1+s2[m:]
  
  def minimumString(self, a:str, b:str, c:str) -> str:
    res = ""
    m = 305
    for word in [
      self.combine(self.combine(a,b),c),
      self.combine(self.combine(a,c),b),
      self.combine(self.combine(b,a),c),
      self.combine(self.combine(b,c),a),
      self.combine(self.combine(c,a),b),
      self.combine(self.combine(c,b),a)
    ]:
      l = len(word)
      if l < m:
        res, m = word, l
      if l == m:
        res = min(word, res)
    return res

