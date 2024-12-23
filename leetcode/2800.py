class Solution:
  
  def combine(self, a:str, b:str) -> str: 
    sa, sb = '', ''
    i, j = len(a)-1, 0
    m = 0
    while i > -1 and j < len(b):
      sa = a[i] + sa
      sb += b[j]
      if sa == sb:
        m = max(m, len(sa))
      i -= 1
      j += 1
    return b if a in b else a if b in a else a+b[m:]

  def calcWord(self, comb:List[str]) -> Tuple[str,int]:
    a,b,c = comb
    s1 = self.combine(self.combine(a,b),c)
    s2 = self.combine(a, self.combine(b,c))
    l1, l2 = len(s1), len(s2)
    return (s1,l1) if l1 < l2 else (s2,l2)
  
  def minimumString(self, a:str, b:str, c:str) -> str:
    combs = [
      [a,b,c],
      [a,c,b],
      [b,a,c],
      [b,c,a],
      [c,a,b],
      [c,b,a]
    ]
    res = []
    m = 305
    for i, comb in enumerate(combs):
      word, l = self.calcWord(comb)
      if l < m:
        res = [(word, l)]
        m = l
      if l == m: res.append((word, l))
    return sorted(res)[0][0]

