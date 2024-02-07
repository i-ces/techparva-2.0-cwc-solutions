#include <bits/stdc++.h>
using namespace std;

string decipher(vector<string> &strings) {

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
