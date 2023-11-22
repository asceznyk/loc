use std::io;
use std::str::FromStr;

const MOD: i64 = 998244353;

#[allow(dead_code)]
fn read_line() -> String {
  let mut buffer = String::new();
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

fn sum(a:&i64, b:i64) -> i64 {
  let mut r = a+b;
  if r >= MOD { r -= MOD; } 
  else if r < 0 { r += MOD; }
  return r;
}

fn mul(a:i64, b:i64) -> i64 {
  return (a * b * 1i64) % MOD;
}

fn solve(n:usize, a:Vec<i64>) {
  let mut res: i64 = 0;
  for b in 0..30 {
    let mut cur: i64 = 0;
    let mut cnt: Vec<i64> = vec![0, 0];
    let mut suml: Vec<i64> = vec![0, 0];
    let mut x: usize = 0;
    cnt[0] = 1;
    for i in 0..n {
      x ^= ((a[i] >> b) & 1) as usize;
      let r = (i+1) as i64;
      cur = sum(&cur, sum(&mul(cnt[x^1], r), -suml[x^1]));
      cnt[x] = sum(&cnt[x], 1);
      suml[x] = sum(&suml[x], r);
    }
    res = sum(&res, mul(1 << b, cur));
  }
  println!("{}", res);
}

fn main() {
  let n = read_num::<usize>().unwrap();
  let a = read_vec::<i64>().unwrap();
  solve(n, a);
}
