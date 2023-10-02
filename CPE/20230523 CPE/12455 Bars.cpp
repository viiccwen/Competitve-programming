#include <bits/stdc++.h>
using namespace std;
bool isPossible = false;
vector<int> bar;
void check(vector<int>& bar, int target, int pos) {
  if (target == 0) {
    isPossible = true;
    return;
  }
  if (pos == bar.size() || target < 0) return;

  check(bar, target - bar[pos], pos + 1);
  check(bar, target, pos + 1);
}

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int target, n;
    isPossible = false;
    cin >> target >> n;

    bar.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> bar[i];

    if (target == 0) isPossible = true;

    if (!isPossible) {
      check(bar, target, 0);
    }

    if (isPossible)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}