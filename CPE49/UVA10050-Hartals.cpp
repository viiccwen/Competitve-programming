#include <bits/stdc++.h>
using namespace std;

void solve() {
  int day, pol, ans = 0;
  cin >> day >> pol;
  vector<vector<bool>> days(pol, vector<bool>(day + 1, 0));
  vector<int> hartal(pol);

  for (int i = 0, tmp; i < pol; i++) {
    cin >> tmp;
    for (int j = 0; j <= day; j += tmp) {
      if (!j) continue;
      days[i][j] = 1;
    }
  }

  for (int i = 1; i <= day; i++) {
    bool flag = 0;
    if (i % 7 == 0 || i % 7 == 6) continue;

    for (int j = 0; j < pol; j++) flag |= days[j][i];

    if (flag) ans++;
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}