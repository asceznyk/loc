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

fn solve(times:&mut Vec<u64>, h:u64) -> (u64, u64) {
  times.sort();
  let m = times.len();
  let mut pref_times = vec![0; m];
  let mut points = 0;
  let mut penalty = 0;
  pref_times[0] = times[0];
  for i in 1..m { pref_times[i] = times[i] + pref_times[i-1]; }
  for i in 0..m {
    if pref_times[i] > h { continue }
    points += 1;
    penalty += pref_times[i];
  }
  return (points, penalty);
}

fn main() {
  let t = read_num::<u64>().unwrap();
  for _ in 0..t {
    let r = read_vec::<u64>().unwrap();
    let (n, m, h) = (r[0], r[1], r[2]);
    let mut place = 1;
    let (mut rudolf_points, mut rudolf_penalty) = (0,0);
    for i in 0..n {
      let mut times = read_vec::<u64>().unwrap();
      let (points, penalty) = solve(&mut times, h);
      if i == 0 { 
        rudolf_points = points;
        rudolf_penalty = penalty;
      }
      if rudolf_points < points { 
        place += 1; 
      } else if (rudolf_points == points) {
        if rudolf_penalty > penalty { place += 1; }
      }
    }
    println!("{}", place);
  }
}


