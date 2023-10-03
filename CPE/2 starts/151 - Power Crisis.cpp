#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, turnoff;

  while (cin >> n && n) {
    n--;
    for (m = 1;; m++) {
      turnoff = 0;
      for (int i = 1; i <= n; i++) turnoff = (turnoff + m) % i;

      if (turnoff == 11) break;
    }

    cout << m << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}