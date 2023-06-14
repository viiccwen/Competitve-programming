#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, ans = 0;
  cin >> n;
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c >= 2) ans++;
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}