use std::io;
use std::str::FromStr;
use std::convert::TryInto;

#[allow(dead_code)]
fn read_line() -> String {
  let mut buffer = String::new();
  io::stdin().read_line(&mut buffer).expect("failed to read line");
  buffer
}

#[allow(dead_code)]
fn read_num<T: FromStr>() -> Result<T, T::Err>{
  read_line().trim().parse::<T>()
}

#[allow(dead_code)]
fn read_vec<T: FromStr>() -> Result<Vec<T>, T::Err> {
  read_line().split_whitespace().map(|x| x.parse::<T>()).collect()
}

fn gcd(mut a: i64, mut b: i64) -> i64 {
  while b != 0 { (a, b) = (b, a % b) };
  a
}

fn gcd_arr(arr: &Vec<i64>) -> i64 {
  let mut res = arr[0];
  for n in 1..arr.len() { res = gcd(res, arr[n]) };
  res
}

fn solve(a: &mut Vec<i64>) {
  let g = gcd_arr(&a);
  if g == 1 { println!("{}", 0); return };    
  let n: i64 = a.len().try_into().unwrap();
  if gcd(g, n) == 1 { println!("{}", 1); return };
  if gcd(g, n-1) == 1 { println!("{}", 2); return };
  if gcd_arr(&vec![g, n, n-1]) == 1 { println!("{}", 3); return };
}

fn main() {
  let t = read_num::<i32>().unwrap();
  for _i in 0..t {
    let _n = read_num::<i32>().unwrap();
    let mut a = read_vec::<i64>().unwrap();
    solve(&mut a);
  }
}

