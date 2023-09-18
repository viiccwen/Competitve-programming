#include <bits/stdc++.h>
using namespace std;

int N, Q;
int cnt = 1;
vector<int> v;

void solve() {
  while (cin >> N >> Q && N != 0 && Q != 0) {
    cout << "CASE# " << cnt++ << ":" << '\n';
    v.assign(N, 0);
    for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());

    for (int i = 1, tmp; i <= Q; i++) {
      cin >> tmp;
      auto ite = find(v.begin(), v.end(), tmp);

      if (ite != v.end())
        cout << tmp << " found at " << &*ite - &*v.begin() + 1 << '\n';
      else
        cout << tmp << " not found" << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}