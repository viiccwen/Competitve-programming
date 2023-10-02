#include <bits/stdc++.h>
using namespace std;

void solve() {
  int t, ans = 0;
  cin >> t;
  vector<int> v(t);

  for (int i = 0; i < t; i++) {
    cin >> v[i];
  }

  for (int i = 0; i < t - 1; i++) {
    for (int j = i + 1; j < t; j++) {
      if (v[i] > v[j]) ans++;
    }
  }

  cout << "Optimal train swapping takes " << ans << " swaps.\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  while (n--) {
    solve();
  }

  return 0;
}
