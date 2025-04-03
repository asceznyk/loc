class Solution:
  def countOrders(self, n:int) -> int:
    memo = {}
    MOD = int(1e9 + 7)
    def calc(k:int) -> int:
      if k == 0: return 1
      if k in memo: return memo[k]
      m = 2*k - 1
      memo[k] = ((m+(m**2))//2)*calc(k-1) % MOD
      return memo[k]
    return calc(n)

