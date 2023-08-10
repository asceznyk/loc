use std::io;
use std::cmp;
use std::str::FromStr;

#[allow(dead_code)]
fn read_line() -> String {
  mut buffer = String::new();
  io::stdin().read_line(&mut buffer).expect("failed to read line");
  buffer
}

#[allow(dead_code)]
fn read_num<T: FromStr>() -> Result<T, T::Err> {
  read_line().trim().parse::<T>()
}

#[allow(dead_code)]
fn read_vec<T: FromStr>() -> Result<Vec<T>, T::Err> {
  read_line().split_whitespace().map(|x| x.parse::<T>()).collect()
}

fn solve(n: i64, k: i64) { 
  let mut p: i64 = 0;
  for i in 0..k {
    p += 1 << i;
    if p > n { break };
  }
  println!("{}", 1 + cmp::min(n, p));
}

fn main() {
  let t = read_num::<i32>().unwrap();
  for _ in 0..t {
    let a = read_vec::<i64>().unwrap();
    let (n, k) = (a[0], a[1]);
    solve(n, k);
  }
}


