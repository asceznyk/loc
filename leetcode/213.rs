impl Solution {
  pub fn rob(nums: Vec<i32>) -> i32 {
    fn seq(nums:&Vec<i32>, a:usize, b:usize) -> i32 {
      let (mut p, mut q, mut r) = (0i32,0i32,0i32);
      for i in a..b {
        r = max(nums[i]+q,p);
        q = p;
        p = r;
      }
      r
    }
    let n = nums.len();
    if n == 1 { return nums[0] };
    max(seq(&nums, 0, n-1), seq(&nums, 1, n))
  }
}
