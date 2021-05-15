use std::io;

const MOD:u64 = 1000000007;

fn expo (a:u64, b:u64, m:u64) -> u64 {
  if b == 0 { return 1; }
  if b == 1 { return a; }
  if b == 2 { return (a*a)%m; }
  if b%2==1 { return (a*expo(a, b-1, m))%m; }
  return expo(expo(a, b/2, m), 2, m);
}

fn main() {
  let mut s = String::new();
  io::stdin().read_line(&mut s)
    .expect("Failed to read size line");
  let n: i32 = s.trim().parse().expect("Not a number");

  for _ in 0..n {
    let mut num = String::new();
    io::stdin().read_line(&mut num)
      .expect("Failed to read size line");
    let mut iter = num.split_whitespace();
    let a: u64 = iter.next().unwrap().parse().unwrap(); 
    let b: u64 = iter.next().unwrap().parse().unwrap();
    let c: u64 = iter.next().unwrap().parse().unwrap();
    
    println!("{}", expo(a, expo(b, c, MOD-1), MOD));
  }
}
