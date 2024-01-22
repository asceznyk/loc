use std::cmp::max;

impl Solution {
  pub fn length_of_lis(nums:Vec<i32>) -> i32 {
    let n: usize = nums.len();
    let mut lmax: i32 = 1;
    let mut length: Vec<i32> = vec![1; n];
    for k in 0..n {
      for i in 0..k {
        if nums[i] >= nums[k] { continue };
        length[k] = max(length[k],length[i]+1);
        lmax = max(lmax, length[k]);
      }
    }
    lmax
  }
}
  
