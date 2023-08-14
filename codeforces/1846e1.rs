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

fn solve(n:isize) {
  let x = ((n as f32).sqrt().floor()) as isize;
  for k in 2isize..x+1 {
    let (mut m, mut t)= (n-1, 1);
    while m >= 0 {
      if m == 0 && t > 2 { println!("YES"); return };
      m -= k.pow(t);
      t += 1;
      if m < 0 { break }; 
    };
  }
  println!("NO");
}

fn main() {
  let t = read_num::<usize>().unwrap();
  for _ in 0..t {
    let n = read_num::<isize>().unwrap();
    solve(n);
  }
}


