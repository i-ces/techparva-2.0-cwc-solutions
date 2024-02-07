use std::io::{self, BufRead};

fn reschedule(schedules: &mut Vec<Vec<u32>>, urgent_meeting: &Vec<u32>) -> Vec<Vec<u32>> {
    schedules.push(urgent_meeting.clone());
    schedules.sort_by(|a, b| a[0].cmp(&b[0]));

    let mut result: Vec<Vec<u32>> = Vec::new();
    for schedule in schedules {
        if result.is_empty() || result.last().unwrap()[1] < schedule[0] {
            result.push(schedule.clone());
        } else {
            result.last_mut().unwrap()[1] = result.last().unwrap()[1].max(schedule[1]);
        }
    }
    result
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
