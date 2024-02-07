#include <bits/stdc++.h>
using namespace std;

string decipher(vector<string> &strings) {
  string result = "";

  for (string &str : strings) {
    int mid = str.length() / 2;

    set<char> first_half(str.begin(), str.begin() + mid);
    set<char> second_half(str.begin() + mid, str.end());

    set<char> intersection;
    set_intersection(first_half.begin(), first_half.end(), second_half.begin(),
                     second_half.end(),
                     inserter(intersection, intersection.begin()));
    if (intersection.empty()) {
      continue;
    } else {
      result += *intersection.begin();
    }
  }

  return result;
}

int main() {
  int n;
  cin >> n;

  vector<string> strings(n);
  for (int i = 0; i < n; i++)
    cin >> strings[i];

  cout << decipher(strings) << endl;
  return 0;
}
