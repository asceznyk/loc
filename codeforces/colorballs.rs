use std::io;
use std::str::FromStr;
use std::collections::HashMap;

#[allow(dead_code)]
struct Random {
    state: usize
}
 
impl Random {
    fn next(&mut self) -> usize {
        let mut x = self.state;
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
        self.state = x;
        x
    }
 
    #[allow(dead_code)]
    fn next_in_range(&mut self, from: usize, to: usize) -> usize {
        assert!(from < to);
        from + self.next() % (to - from)
    }
 
    #[allow(dead_code)]
    fn next_double(&mut self) -> f64 {
        (self.next() as f64) / (std::usize::MAX as f64)
    }
 
    #[allow(dead_code)]
    fn new(seed: usize) -> Self {
        assert_ne!(seed, 0);
        Self {
            state: seed,
        }
    }
}

#[allow(dead_code)]
fn random_vector(rnd:&mut Random, n:usize, r:usize) -> Vec<usize> {
    let mut a = vec![];
    for _ in 0..n {
        a.push(rnd.next_in_range(0, r));
    }
    a
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

fn solve(a: &[usize]) -> usize {
    let n: usize = a.len();

    let mut r: HashMap<usize, Vec<usize>> = HashMap::new(); 
    for i in 0..n {
        r.entry(a[i]).or_insert_with(Vec::new).push(i);
    } 
    if r.keys().len() == n { return 0; }

    let mut emax = 0;
    for (_k, v) in r {
        'outer: for i in 0..v.len() {
            'inner: for j in (i+1)..v.len() {
                let mut b = a.to_vec();
                b.drain(v[i]..=v[j]);
                let l = (n - b.len()) + solve(&b);
                if l > emax { emax = l; }
                if emax == n { break 'outer; }
            }
        }
    }

    return emax;
}

fn test() {
    //println!("{}", solve(&vec![1,2,2,3,3]));
    //println!("{}", solve(&vec![1,2,1,2]));
    //println!("{}", solve(&vec![1,2,3,4,5]));
    //println!("{}", solve(&vec![4,5,8,6,7,9,4,8,9,8]));
    //println!("{}", solve(&vec![5,4,8,6,9,7,4,9,1,1,8]));

    let n = 15;
    let mut rnd = Random::new(48058);
    for _i in 0..10 {
        let v = random_vector(&mut rnd, n, n);
        println!("{:?}", v);
        println!("{}", solve(&v))
    }
}

fn input() {
    let t = read_num::<i32>().unwrap();
    for _ in 0..t {
        let _n = read_num::<i32>().unwrap();
        let mut a = read_vec::<usize>().unwrap();
        println!("{}", solve(&mut a));
    }
}

fn main () {
    test();
    //input();
}

