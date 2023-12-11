class Solution:
  def isPalindrome(self, s:str) -> bool:
    s = s.lower()
    alphabet = 'abcdefghijklmnopqrstuvwxyz0123456789'
    n = ''
    for c in s:
      if c not in alphabet: continue
      n += c
    print(n)
    return n == n[::-1]

