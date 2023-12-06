from typing import List

class Solution:

  def encode(self, strs:List[str]):
    s = ""
    for w in strs: s += f"{len(w)}|{w}"
    return s

  def decode(self, s:str):
    i, j = 0, 0
    strs = []
    while i < len(s):
      c = s[i]
      if c == '|':
        n = int(s[j:i])
        strs.append(s[i+1:i+n+1])
        i += n
        j = i+1
      i += 1
    return strs

