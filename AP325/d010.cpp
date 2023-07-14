#include <bits/stdc++.h>
using namespace std;
int N;
void solve() {
  cin >> N;
  vector<int> v(N);
  for (auto &i : v) cin >> i;
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  cout << v.size() << '\n';
  for (auto i : v) cout << i << ' ';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}