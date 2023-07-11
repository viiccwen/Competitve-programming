#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
ll L;
vector<ll> p;

ll cut(ll left, ll right) {
  if (right - left <= 1) return 0;
  ll mid = (p[right] + p[left]) / 2;
  ll idx =
      &*lower_bound(p.begin() + left, p.begin() + right, mid) - &*(p.begin());
  if (p[idx - 1] - p[left] >= p[right] - p[idx]) idx--;
  return (p[right] - p[left]) + cut(left, idx) + cut(idx, right);
}

void solve() {
  cin >> N >> L;
  p.resize(N + 1);
  p[0] = 0, p[N + 1] = L;
  for (int i = 1; i <= N; i++) cin >> p[i];

  cout << cut(0, N + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}