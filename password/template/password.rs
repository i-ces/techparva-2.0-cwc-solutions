use std::collections::HashSet;
use std::io::{self, BufRead};

fn decipher(strings: &Vec<String>) -> String {

}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let n = stdin_iterator
        .next()
        .unwrap()
        .unwrap()
        .trim()
        .parse::<usize>()
        .unwrap();

    let mut strings: Vec<String> = Vec::with_capacity(n);
    for _ in 0..n {
        let string = stdin_iterator.next().unwrap().unwrap().trim().to_string();
        strings.push(string);
    }

    println!("{}", decipher(&strings));
}
