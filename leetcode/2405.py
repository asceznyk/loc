class Solution:
  def partitionString(self, s:str) -> int:
    freq = {s[0]:1}
    ans = 1
    for c in s[1:]:
      if not freq.get(c, 0):
        freq[c] = 1
      else:
        ans += 1
        freq = {}
        freq[c] = 1
    return ans
