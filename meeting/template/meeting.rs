use std::io::{self, BufRead};

fn reschedule(schedules: &mut Vec<Vec<u32>>, urgent_meeting: &Vec<u32>) -> Vec<Vec<u32>> {

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

    let mut schedules: Vec<Vec<u32>> = Vec::with_capacity(n);

    for _ in 0..n {
        let schedule = stdin_iterator
            .next()
            .unwrap()
            .unwrap()
            .trim_end()
            .split_whitespace()
            .map(|s| s.parse::<u32>().unwrap())
            .collect::<Vec<_>>();
        schedules.push(schedule);
    }

    let urgent_meeting = stdin_iterator
        .next()
        .unwrap()
        .unwrap()
        .trim_end()
        .split_whitespace()
        .map(|s| s.parse::<u32>().unwrap())
        .collect::<Vec<_>>();

    let result = reschedule(&mut schedules, &urgent_meeting);
    for schedule in result {
        println!("{} {}", schedule[0], schedule[1]);
    }
}
