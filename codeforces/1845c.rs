use std::ioe
use std::cmp::max;
use std::str::FromStr;

#[allow(dead_code)]
fn read_line() -> String {
  let mut buffer = String::new();
  io::stdin()
    .read_line(&mut buffer)
    .expect("failed to read line");

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

#[allow(dead_code)]
fn char_int(x:char) -> u32 {
  const RADIX:u32 = 10;
  x.to_digit(RADIX).unwrap()
}

#[allow(dead_code)]
fn str_chrarr(s:String) -> Vec<char> {
  s.chars().collect::<Vec<char>>()
}

fn solve(s:Vec<char>, l:String, r:String) {
  let (n, m) = (s.len(), l.len());

  let mut x = 0;
  for i in 0..m {
    let mut j = x;
    let li:u32 = char_int(l.as_bytes()[i] as char);
    let ri:u32 = char_int(r.as_bytes()[i] as char);
    for c in li..=ri {
      let mut k = x;
      while k < n && char_int(s[k]) != c { k += 1; }
      j = max(k, j);
    }
    x = j+1;
  }
  println!("{}", if x > n {"YES"} else {"NO"});
}

fn main() {
  let t = read_num::<u32>().unwrap();
  for _ in 0..t {
    let s = read_num::<String>().unwrap();
    let _ = read_num::<u32>().unwrap();
    let l = read_num::<String>().unwrap();
    let r = read_num::<String>().unwrap();
    solve(str_chrarr(s), l, r);
  }
}



