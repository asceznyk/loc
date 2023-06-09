use std::io;
use std::str::FromStr;

fn gcd(mut a: i64, mut b: i64) -> i64 {
    while b != 0 { (a, b) = (b, a % b) };
    a
}

fn gcd_arr(arr: &Vec<i64>) -> i64 {
    let mut res = arr[0];
    for i in 1..arr.len() { res = gcd(res, arr[i]) };
    res
}

fn check_gcd(a: &Vec<i64>) -> bool {
    gcd_arr(&a) == 1
}

fn solve(a: &mut Vec<i64>) {
    if check_gcd(&a) { println!("{}", 0); return };

    let n = a.len();
    for i in (0..n).rev().step_by(1) {
        let temp1 = a[i];
        a[i] = gcd(a[i], (i+1) as i64);
        if check_gcd(&a) { println!("{}", n-i); return };

        for j in (i+1..n).rev().step_by(1) {
            let temp2 = a[j];
            a[j] = gcd(a[j], (j+1) as i64); 
            if check_gcd(&a) { println!("{}", (n-i) + (n-j)); return; }
            a[j] = temp2;
        }

        a[i] = temp1;
    }
}

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

fn main() {
    let t = read_num::<i32>().unwrap();
    for _i in 0..t {
        let _n = read_num::<i32>().unwrap();
        let mut a = read_vec::<i64>().unwrap();
        solve(&mut a);
    }
}

