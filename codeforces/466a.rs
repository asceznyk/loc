use std::io;
use std::cmp::max;
use std::str::FromStr;

#[allow(dead_code)]
fn read_line() -> String {
  let mut buffer = String::new();
  io::stdin().read_line(&mut buffer).expect("failed to read line");
  buffer
}

#[allow(dead_code)]
fn read_vec<T: FromStr>() -> Result<Vec<T>, T::Err> {
  read_line().split_whitespace().map(|x| x.parse::<T>()).collect()
}

fn solve(n:usize, m:usize, a:usize, b:usize) {
  let mmod = if n%m == 0 {n/m} else {(n/m)+1};
  let exps = vec![mmod*b, n*a, (n/m)*b+(n-(n/m)*m)*a];
  println!("{}", *exps.iter().min().unwrap());
}

fn main() {
  let x = read_vec::<usize>().unwrap();
  let (n, m, a, b) = (x[0], x[1], x[2], x[3]);
  solve(n, m, a, b);
}




