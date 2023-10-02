#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c, d, L;

  while (cin >> a >> b >> c >> d >> L) {
    if (a == 0 && b == 0 && c == 0 && d == 0 && L == 0) break;

    int ans = 0;
    for (int i = 0; i <= L; i++) {
      int f = a * i * i + b * i + c;
      if (!(f % d)) ans++;
    }
    cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}