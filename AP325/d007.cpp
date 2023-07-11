#include <bits/stdc++.h>
using namespace std;
#define LL long long
vector<LL> a;
int N;
LL P, ans;

void rec(int i, LL sum) {
  if (i >= N) {
    if (sum <= P) ans = max(ans, sum);
    return;
  }
  rec(i + 1, sum + a[i]);
  rec(i + 1, sum);
  return;
}

void solve() {
  cin >> N >> P;
  a.resize(N);
  for (auto &i : a) cin >> i;
  rec(0, 0);
  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}