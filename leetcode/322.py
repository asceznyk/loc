from typing import List

class Solution:
  def coinChange(self, coins:List[int], amount:int) -> int:
    dp = [0] + [amount+1 for _ in range(amount)]
    for i in range(1, amount+1):
      for x in coins:
        if i-x < 0: continue
        dp[i] = min(dp[i-x]+1, dp[i])
    ans = dp[amount]
    return -1 if ans == amount+1 else ans


