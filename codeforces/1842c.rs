use std::io;
use std::str::FromStr;
use std::cmp::min;

#[allow(dead_code)]
fn read_line() -> String {
    let mut buffer = String::new();
    io::stdin()
        .read_line(&mut buffer)
        .expect("failed to read line");
 
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

fn solve(a: &[usize]) {
    let n: usize = a.len();
    let mut dp = Vec::with_capacity(n+1);
    let mut buc = Vec::with_capacity(n+1);

    dp.push(0);
    for _ in 0..n+1 { buc.push(0x3f3f3f); };
    for i in 1..n+1 {
        let c = a[i-1];
        dp.push(min(dp[i-1]+1, buc[c]));
        buc[c] = min(dp[i-1], buc[c]);
    }

    println!("{}", n-dp[n]);
}

fn main() {
    let t = read_num::<i32>().unwrap();
    for _ in 0..t {
        let _n = read_num::<i32>().unwrap();
        let mut a = read_vec::<usize>().unwrap();
        solve(&mut a);
    }
}

