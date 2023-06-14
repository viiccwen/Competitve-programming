#include <bits/stdc++.h>
using namespace std;

void solve() {
  int w;
  cin >> w;
  (w % 2 == 0) && (w > 2) ? cout << "YES" : cout << "NO";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}