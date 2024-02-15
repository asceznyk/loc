impl Solution {
  fn single_number(nums: Vec<i32>) -> i32 {
    let mut p:i32 = nums[0];
    for i in 1..nums.len() {
      p ^= nums[i];
    }
    p
  }
}
