#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

bool tmp(pair<int, int> a, pair<int, int> b) {
  if (a.s == b.s)
    return a.f > b.f;
  else
    return a.s < b.s;
}

void solve() {
  string s;
  bool flag = 0;
  map<int, int> map;
  vector<pair<int, int>> v;
  while (getline(cin, s)) {
    if (!flag)
      flag = 1;
    else
      cout << '\n';

    for (auto c : s) map[int(c)]++;
    for (auto i : map) v.push_back({i.f, i.s});
    sort(v.begin(), v.end(), tmp);
    for (auto i : v) cout << i.f << ' ' << i.s << '\n';

    v.clear();
    map.clear();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}