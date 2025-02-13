class Solution:
  def frequencySort(self, s:str) -> str:
    freq = {}
    for c in s:
      if c not in freq:
        freq[c] = 1
        continue
      freq[c] += 1
    arr = sorted(freq.items(), key=lambda i: i[1], reverse=True)
    ans = ""
    for c,f in arr:
      ans += (c*f)
    return ans


