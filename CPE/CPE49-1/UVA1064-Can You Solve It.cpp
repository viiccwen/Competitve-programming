#include <bits/stdc++.h>
using namespace std;

int cal(int x, int y) {
  int n = x + y;
  return n * (n + 1) / 2 + x;
}

void solve() {
  int n, dis1, dis2;
  cin >> n;

  for (int i = 1, a, b, c, d; i <= n; i++) {
    cin >> a >> b >> c >> d;
    dis1 = cal(a, b);
    dis2 = cal(c, d);
    cout << "Case " << i << ": " << dis2 - dis1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}

/*
0 0 0

0 1 1 *
1 0 2

0 2 3 *
1 1 4
2 0 5

0 3 6 *
1 2 7
2 1 8
3 0 9

0 4 10 *
1 3 11
2 2 12
3 1 13
4 0 14

1+2+3+4....
s = n * (1 + n) / 2 + x
*/