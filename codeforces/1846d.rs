use std::io;
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

fn solve(dims:&Vec<i64>, idxs:&Vec<i64>) {
  let (n, d, h) = (dims[0] as usize, dims[1] as f64, dims[2] as f64);
  let full_area = ((n as f64)*d*h)/2.0;
  let mut int_area = 0.0;
  for i in 0..(n-1) {
    let (a, b) = (idxs[i+1] as f64, idxs[i] as f64);
    if (a-b) >= h { continue }; 
    int_area += d*(((h - (a-b)) as f64).powf(2.0)/h)/2.0; 
  }
  println!("{}", (full_area - int_area));
}

fn main() {
  let t = read_num::<i64>().unwrap();
  for _ in 0..t {
    let dims = read_vec::<i64>().unwrap();
    let idxs = read_vec::<i64>().unwrap();
    solve(&dims, &idxs);
  }
}

