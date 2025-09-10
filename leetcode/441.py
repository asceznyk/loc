class Solution:
  def arrangeCoins(self, n:int) -> int:
    l, r = 1, 2**32
    while l <= r:
      m = (l+r)//2
      k = (m*(m+1))/2
      if k > n: r = m-1
      elif k <= n: l = m+1
    return r




