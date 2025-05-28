class Solution:
  def addSpaces(self, s:str, spaces:List[int]) -> str:
    p = 0
    words = []
    for i, x in enumerate(spaces):
      words.append(s[p:x])
      p = x
    words.append(s[p:])
    return " ".join(words)




