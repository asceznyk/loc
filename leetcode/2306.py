class Solution:
  def distinctNames(self, ideas:List[str]) -> int:
    n = len(ideas)
    prefixSuffix = {}
    letters = set()
    for idea in ideas:
      char, suffix = idea[0], idea[1:]
      letters.add(char)
      if prefixSuffix.get(char, 0): prefixSuffix[char].append(suffix)
      else: prefixSuffix[char] = [suffix]
    ans = 0
    for x in letters:
      for y in letters:
        if x == y: continue
        xcnt, ycnt = 0, 0
        xlist = {x:1 for x in prefixSuffix[x]}
        ylist = {y:1 for y in prefixSuffix[y]}
        for suf1 in xlist:
          if ylist.get(suf1,0): continue
          xcnt += 1
        for suf2 in ylist:
          if xlist.get(suf2,0): continue
          ycnt += 1
        ans += (xcnt*ycnt)
    return ans


