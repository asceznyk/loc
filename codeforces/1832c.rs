use std::io;
use std::cmp;
use std::str::FromStr;

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

fn contrast(a: &[i64]) -> i64 {
  let mut c = 0;
  for i in 1..a.len() { c += (a[i-1]-a[i]).abs() };
  c
}

fn solve(a: &[i64]) -> usize {
  let n = a.len();
  let c = contrast(a);
  if n == 1 || c == 0 {  return 1 };
  if n == 2 { return 2 };
  let (mut i, mut k) = (0,0);
  for j in 2..n {
    let r = a[j-1];
    if r <= cmp::max(a[i], a[j]) && r >= cmp::min(a[i], a[j]) { 
      k += 1; 
    } else { i = j-1; }
  }
  return n-k;
}

fn next() {
  let t = read_num::<i32>().unwrap();
  for _i in 0..t {
    let _n = read_num::<i32>().unwrap();
    let mut a = read_vec::<i64>().unwrap();
    println!("{}", solve(&mut a));
  }
}

fn main() {
  next();
}

