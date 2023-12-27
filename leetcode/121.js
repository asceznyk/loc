const maxProfit = function(prices) {
  let profit = 0;
  let mp = prices[0]
  for (let i = 1; i < prices.length; i++) {
    mp = Math.min(prices[i-1], mp)
    let diff = prices[i] - mp
    profit = Math.max(diff, profit)
  }
  return profit
}

