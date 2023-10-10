#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b;
  while (cin >> a >> b) {
    cout << a << ' ' << b << ' ';
    if (b < a) swap(a, b);

    int maximum = 0;
    for (int i = a; i <= b; i++) {
      int cur = 0;
      int n = i;
      while (n != 1) {
        cur++;
        if (n % 2)
          n = 3 * n + 1;
        else
          n /= 2;
      }

      maximum = max(maximum, cur);
    }

    cout << maximum + 1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}