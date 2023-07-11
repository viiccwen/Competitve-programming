#include <bits/stdc++.h>
using namespace std;
#define P 10009
#define LL long long

vector<int> a;
int n;
LL ans = 0;

void rec(int i, int prod) {
  if (i >= n) {
    if (prod == 1) ans++;
    return;
  }
  rec(i + 1, (prod * a[i] % P));
  rec(i + 1, prod);
  return;
}

void solve() {
  cin >> n;
  a.resize(n);
  for (auto &i : a) cin >> i;
  rec(0, 1);
  cout << ans - 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}