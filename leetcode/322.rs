use std::cmp::min;

fn coin_change(coins:Vec<i32>, amount:i32) -> i32 {
  let n = (amount+1) as usize;
  let mut dp: Vec<i32> = vec![amount+1; n];
  dp[0] = 0;
  for i in 0..n {
    for x in coins.iter(){
      dp[i] = min(
        if (i as i32)-x >= 0 { 
          dp[i-(*x as usize)]+1 
        } else { amount+1 }, 
        dp[i]
      );
    }
  }
  let ans = dp[n-1];
  if ans == amount+1 { -1 } else { ans }
}


