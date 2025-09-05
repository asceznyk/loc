class Solution:
  def findRepeatedDnaSequences(self, s:str) -> List[str]:
    if len(s) < 10: return []
    init = s[:10]
    cMap = {init:1}
    for i in range(10, len(s)):
      init += s[i]
      init = init[1:]
      if not cMap.get(init): cMap[init] = 0
      cMap[init] += 1
    return [k for k,v in cMap.items() if v > 1]

