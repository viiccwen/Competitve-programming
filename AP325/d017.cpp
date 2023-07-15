#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL N, P, num;

LL exp(int x, int y, int p) {
  if (y == 0) return 1;
  if (y & 1) return (exp(x, y - 1, p) * x) % p;
  LL tmp = exp(x, y / 2, p);
  return (tmp * tmp) % p;
}

void solve() {
  cin >> N >> P;
  while (N--) {
    cin >> num;
    cout << exp(num, P - 2, P) << ' ';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}