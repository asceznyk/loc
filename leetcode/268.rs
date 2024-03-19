impl Solution {
  pub fn missing_number(nums: Vec<i32>) -> i32 {
    let n = nums.len();
    let mut p = 0;
    for i in 0..n { p ^= (i as i32) ^ nums[i]; }
    p ^ (n as i32)
  }
}

