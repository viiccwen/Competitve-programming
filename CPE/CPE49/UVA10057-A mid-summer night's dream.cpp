#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
  vector<int> v(n);
  int t = 0, total = 0;

  for (int i = 0; i < n; i++) cin >> v[i];

  sort(v.begin(), v.end());

  int mid1 = v[(n - 1) / 2], mid2 = v[n / 2];

  int cnt = 0;
  for (auto i : v)
    if (i == mid1 || i == mid2) cnt++;

  cout << mid1 << ' ' << cnt << ' ' << mid2 - mid1 + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  while (cin >> n) {
    solve(n);
  }

  return 0;
}
