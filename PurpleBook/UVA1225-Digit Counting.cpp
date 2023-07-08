#include <bits/stdc++.h>
using namespace std;
vector<int> digit;

void solve() {
  string s = "";
  digit.assign(10, 0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) s += to_string(i);

  for (int i = 0; i < s.size(); i++) digit[s[i] - '0']++;

  for (int i = 0; i < 10; i++) {
    cout << digit[i] << ' ';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  while (N--) solve();
}
