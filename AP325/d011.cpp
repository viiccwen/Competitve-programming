#include <bits/stdc++.h>
using namespace std;
int N;
void solve() {
  cin >> N;
  vector<int> v(N);
  for (auto &i : v) cin >> i;
  vector<int> g = v;
  sort(g.begin(), g.end());
  g.erase(unique(g.begin(), g.end()), g.end());
  map<int, int> mp;
  int k = 0;
  for (auto i : g) mp[i] = k++;
  for (auto i : v) cout << mp[i] << ' ';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}