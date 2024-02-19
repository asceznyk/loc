impl Solution {
  pub fn can_jump(nums: Vec<i32>) -> bool {
    let n:i32 = nums.len() as i32;
    let (mut y, mut j) = (0i32, 0i32);
    for i in 0..n {
      let x:i32 = nums[(i as usize)];
      if x+(i as i32) >= y+j { (y,j) = (x,i as i32) };
      if x == 0 && (y+j <= i && i < n-1) { return false; }
    }
    true
  }
}
