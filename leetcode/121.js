const maxProfit = function(prices) {
  let dp = []
  dp[0] = 0
  let mp = 10000000000
  for (let i = 1; i < prices.length; i++) {
    mp = Math.min(prices[i-1], mp)
    let diff = prices[i] - mp
    dp[i] = Math.max(diff, dp[i-1])
  }
  return dp[dp.length-1]
}

