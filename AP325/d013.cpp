#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL t = 0;

LL exp2(LL x, LL y, LL p) {
  if (y == 0) return 1;
  if (y & 1) return (exp2(x, y - 1, p) * x) % p;
  LL tmp = exp2(x, y / 2, p);
  return (tmp * tmp) % p;
}

void exp(string x, LL p) {
  if (x.size() == 0) return;

  t = (t * 10 + x[0] - '0') % p;
  x.erase(x.begin());
  exp(x, p);
}

void solve() {
  LL y, p;
  string x;
  cin >> x >> y >> p;
  exp(x, p);
  cout << exp2(t, y, p);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}