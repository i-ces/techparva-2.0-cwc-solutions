#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; }

vector<vector<int>> reschedule(vector<vector<int>> &schedules,
                               vector<int> &urgent_meeting) {
  vector<vector<int>> result;
  schedules.push_back(urgent_meeting);
  sort(schedules.begin(), schedules.end(), compare);

  for (vector<int> schedule : schedules) {
    if (result.empty() || result.back()[1] < schedule[0]) {
      result.push_back(schedule);
    } else {
      result.back()[1] = max(result.back()[1], schedule[1]);
    }
  }

  return result;
}

int main() {
  int n, start, end;
  vector<vector<int>> schedules;
  vector<int> urgent_meeting(2);

  cin >> n;
  while (n--) {
    cin >> start >> end;
    schedules.push_back({start, end});
  }
  cin >> urgent_meeting[0] >> urgent_meeting[1];

  vector<vector<int>> result = reschedule(schedules, urgent_meeting);
  for (vector<int> schedule : result) {
    cout << schedule[0] << " " << schedule[1] << endl;
  }
}
