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

fn solve(n:usize, k:usize) {
  let mut ans:usize = 0;
  for i in 1..n+1 {
    let mut sx = n as i64;
    let mut sp = i as i64;
    let mut valid:bool = true;
    for _ in 0..k-2 {
      let tmp = sp;
      sp = sx - sp;
      sx = tmp;
      if sx < 0 || sp < 0 || sx < sp {
        valid = false;
        break
      }
    }
    ans += if valid { 1 } else { 0 };
  }
  println!("{}", ans);
}

fn main() {
  let t = read_num::<usize>().unwrap();
  for _ in 0..t {
    let a = read_vec::<usize>().unwrap();
    let (n, k) = (a[0], a[1]); 
    solve(n, k);
  }
}

