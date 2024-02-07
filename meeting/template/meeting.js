process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => {
    inputString += inputStdin;
});

process.stdin.on("end", () => {
    inputString = inputString.split("\n");
    main();
});

function readLine() {
    return inputString[currentLine++];
}

/**
 * @param {number[][]} schedules - An array of existing meeting schedules, where each schedule is represented as [start, end] pair.
 * @param {number[]} urgent_meeting - The urgent meeting to be inserted, represented as [start, end] pair.
 * @returns {number[][]} The updated schedule with merged intervals, where each element is an [start, end] pair representing a meeting.
 */
function reschedule(schedules, urgent_meeting) {

}

function main() {
    const schedules = [];
    const n = parseInt(readLine());
    for (let i = 0; i < n; i++) {
        const [start, end] = readLine().split(" ").map(Number);
        schedules.push([start, end]);
    }

    const [urgentStart, urgentEnd] = readLine().split(" ").map(Number);
    const urgentMeeting = [urgentStart, urgentEnd];

    const result = reschedule(schedules, urgentMeeting);
    for (const schedule of result) {
        console.log(`${schedule[0]} ${schedule[1]}`);
    }
}
