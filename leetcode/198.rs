impl Solution {
  pub fn rob(nums: Vec<i32>) -> i32 {
    if nums.len() == 1 { return p; }
    let (mut p, mut q, mut r) = (0i32, 0i32,0i32);
    for i in 0..nums.len() {
      r = max(nums[i]+q,p);
      q = p;
      p = r;
    }
    r
  }
}
