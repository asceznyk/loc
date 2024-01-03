class Solution:
  def lengthOfLongestSubstring(self, s:str) -> int:
    m, c = 0, 0
    ss = ""
    for char in s:
      if char in ss:
        ss = ss[ss.index(char)+1:]
        c = len(ss)
      ss += char
      c += 1
      if c > m: m = c
    return m

