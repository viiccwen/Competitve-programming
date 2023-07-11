#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pii pair<int, int>
vector<pii> p;
int N;

void solve() {
  cin >> N;
  p.resize(N);
  for (auto &i : p) cin >> i.f >> i.s;
  sort(p.begin(), p.end());
  vector<int> v;
  for (auto i : p) {
    if (v.empty() || v.back() <= i.s)
      v.push_back(i.s);
    else
      v[&*upper_bound(v.begin(), v.end(), i.s) - &*v.begin()] = i.s;
  }

  cout << v.size();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}