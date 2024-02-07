#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> reschedule(vector<vector<int>> &schedules,
                               vector<int> &urgent_meeting) {

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
