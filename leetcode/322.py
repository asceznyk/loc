from typing import List

INF = (2**32)-1
class Solution:
  def coinChange(self, coins:List[int], amount:int) -> int:
    dp = [0] + [INF for _ in range(amount)]
    for i in range(amount+1):
      for x in coins:
        dp[i] = min(dp[i-x]+1 if i-x >= 0 else INF, dp[i])
    ans = dp[amount]
    return -1 if ans == INF else ans


