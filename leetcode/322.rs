use std::cmp::min;

impl Solution {
  fn coin_change(coins:Vec<i32>, amount:i32) -> i32 {
    let mut dp: Vec<i32> = vec![amount+1; (amount+1) as usize];
    dp[0] = 0;
    for i in 1..=amount {
      let a = i as usize;
      for x in &coins {
        if i-x < 0 { continue };
        dp[a] = min(dp[a-(*x as usize)]+1, dp[a]);
      }
    }
    let ans = dp[amount as usize];
    if ans == amount+1 { -1 } else { ans }
  }
}
