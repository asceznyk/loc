use std::cmp::min;

impl Solution {
  fn min_cost_climbing_stairs(cost: &Vec<i32>) -> i32 {
    let n = cost.len();
    let mut ncost: Vec<i32> = vec![0];
    ncost.extend(cost);
    ncost.extend(vec![0]);
    let mut dp: Vec<i32> = vec![1000; n+2];
    dp[0] = ncost[0];
    dp[1] = ncost[1];
    for i in 2..n+2 {
      dp[i] = min(dp[i-1], dp[i-2]) + ncost[i];
    }
    return dp[n+1] as i32;
  }
}
