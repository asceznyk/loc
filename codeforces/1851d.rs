use std::io;
use std::str::FromStr;
use std::iter::FromIterator;
use std::collections::HashSet;

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

fn psum_to_arr(p:&Vec<i128>) -> Vec<i128> {
  let n = p.len();
  let mut res: Vec<i128> = vec![0; n];
  res[0] = p[0];
  for i in 1..n { res[i] = p[i] - p[i-1]; }
  res
}

fn is_permutation(a:&Vec<i128>) -> bool {
  let n = a.len();
  for i in 0..n {
    if a[i] < 1 || a[i] > (n as i128) {
      return false;
    }
  }
  let set: HashSet<i128> = HashSet::from_iter(a.iter().cloned());
  set.len() == n
}

fn solve(n:i128, a:&mut Vec<i128>) {
  let ubound = (n*(n+1))/2;
  if a[a.len()-1] != ubound {
    a.push(ubound);
    let b = psum_to_arr(&a);
    if is_permutation(&b) { println!("YES"); } else { println!("NO"); }
    return;
  }
  a.splice(0..0, vec![(0 as i128)].iter().cloned());
  let mut comp: HashSet<i128> = HashSet::new();
  for i in 1..n+1 { comp.insert(i); }
  let mut diffs: Vec<i128> = vec![];
  for i in 1..a.len() {
    let diff = a[i]-a[i-1];
    if comp.contains(&diff) { comp.remove(&diff); }
    diffs.push(diff);
  }
  let csum: i128 = comp.iter().sum();
  if comp.len() == 2 && a[1] == csum { println!("YES"); return; }
  if comp.len() == 2 && diffs.contains(&csum) { println!("YES"); return; }
  println!("NO");
}

fn main() {
  let t = read_num::<usize>().unwrap();
  for _ in 0..t {
    let n = read_num::<i128>().unwrap();
    let mut a = read_vec::<i128>().unwrap();
    solve(n, &mut a);
  }
}




