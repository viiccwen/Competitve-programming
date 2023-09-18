#include <bits/stdc++.h>
using namespace std;
#define LL long long

set<LL> S({0});

void solve() {
  int N, K;
  LL prefix_sum = 0, ans = 0;
  cin >> N >> K;

  for (int i = 0, tmp; i < N; i++) {
    cin >> tmp;
    prefix_sum += tmp;
    auto ite = S.lower_bound(prefix_sum - K);
    if (ite != S.end()) ans = max(ans, prefix_sum - *ite);
    S.insert(prefix_sum);
  }

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}