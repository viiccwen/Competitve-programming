#include <bits/stdc++.h>

using namespace std;

void solve() {
  int s, n, k, R = 50;
  double p, q, ans;

  cin >> s;
  for (int i = 0; i < s; i++) {
    cin >> n >> p >> k;
    if (p == 0)
      ans = 0;
    else {
      q = 1 - p;
      ans = pow(q, k - 1) * p * (1 - pow(pow(q, n), R)) / (1 - pow(q, n));
    }

    cout << fixed << setprecision(4) << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
/*
R round = 50
n total people
p success percentage
q lose percentage = 1 - p
k required

first round:
p
q*p
q^2*p
.
.
q^(k-1)*p

second round:
q^n * p
q^n * q * p
q^n * q^2 * p
.
.
q^n * q^(k-1) * p

R round = q^((R-1)*n) * q(n-1) * p

use a1 * (1 - r^n) / 1 - r

a1 = q^(k-1) * p
r  = q^n

q^(k-1) * p * (1 - q^n^R) / 1 - q^n
*/