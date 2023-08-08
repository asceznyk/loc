use std::io;
use std::cmp;
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



