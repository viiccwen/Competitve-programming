#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k, cnt = 0;
  cin >> n >> k;

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int target = v[k - 1];

  for (int i = 0; i < n; i++) {
    if (v[i] >= target && v[i])
      cnt++;
    else
      break;
  }

  cout << cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}