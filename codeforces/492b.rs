use std::io;
use std::str::FromStr;

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

fn solve(n:usize, l:f64, a:&mut Vec<f64>) {
  a.sort_by(|x, y| x.partial_cmp(y).unwrap());
  let mut x = 0.0;
  for i in 1..n {
    let diff = a[i]-a[i-1]; 
    x = if diff > x { diff } else { x };
  }
  println!("{}", f64::max(x/2.0, f64::max(a[0], l- a[n-1])));
}

fn main() {
  let x = read_vec::<i64>().unwrap();
  let (n, l) = (x[0] as usize, x[1] as f64);
  let mut a = read_vec::<f64>().unwrap();
  solve(n, l, &mut a);
}




