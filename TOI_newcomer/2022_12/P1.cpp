#include <bits/stdc++.h>
using namespace std;

void solve() {
  int s, m, l;
  int t;
  cin >> s >> m >> l;
  cin >> t;

  int total = s + m + l;
  vector<int> park(t);

  for (int i = 0; i < t; i++) cin >> park[i];
  sort(park.begin(), park.end());

  for (int i = 0; i < t; i++) {
    if (park[i] < 200) {
      if (s)
        s--;
      else if (m)
        m--;
      else if (l)
        l--;
    } else if (park[i] >= 200 && park[i] < 500) {
      if (m)
        m--;
      else if (l)
        l--;
    } else if (park[i] >= 500 && l)
      l--;
  }

  cout << total - s - m - l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}