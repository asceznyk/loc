impl Solution {
  fn count_bits(n: i32) -> Vec<i32> {
    let mut nbits:Vec<i32> = vec![0; (n+1) as usize];
    (1..=n).for_each(|i| {
      let odd:i32 = if i%2 == 0 { 0 } else { 1 }; 
      nbits[i as usize] = nbits[(i/2) as usize] + odd;
    });
    nbits
  }
}

fn main() {
  println!("{:?}", count_bits(10));
  println!("{:?}", count_bits(2));
  println!("{:?}", count_bits(5));
}
