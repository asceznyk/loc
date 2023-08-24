use std::io;
use std::str::FromStr;
use std::fmt::Display;

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

fn print_format_vec<T: Display>(v:&Vec<T>) {
  let mut s = String::new();
  for i in 0..v.len() {
    s.push_str(&format!("{} ", v[i]).to_string());
  }
  println!("{}", s);
}

fn solve(n:i64, b:&mut Vec<i64>) {
  b.sort();
  let mut p = 1;
  let mut k = n-1;
  let mut a = vec![];
  for i in 0..b.len() {
    if p == k {
      k -= 1;
      p = 0;
      a.push(b[i]);
    }
    p += 1;
  };
  a.push(*a.last().unwrap());
  print_format_vec::<i64>(&a);
}

fn main() {
  let t = read_num::<usize>().unwrap();
  for _ in 0..t {
    let n = read_num::<i64>().unwrap();
    let mut b = read_vec::<i64>().unwrap();
    solve(n, &mut b);
  }
}

