#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> cost(36);
vector<int> cheap(36);
ll minn, total, num;
int idx, Round;

void solve() {
  int N;
  cin >> N;
  Round = 1;
  while (N--) {
    for (auto &i : cost) cin >> i;
    int k;
    cin >> k;
    if (Round > 1) cout << '\n';
    cout << "Case " << Round++ << ":\n";
    while (k--) {
      cin >> num;
      minn = INT_MAX;
      cout << "Cheapest base(s) for number " << num << ":";

      for (int base = 2; base <= 36; base++) {
        total = 0;
        ll tmp = num;
        while (tmp > 0) {
          total += cost[tmp % base];
          tmp /= base;
        }

        if (total < minn) {
          minn = total;
          idx = 1;
          cheap[0] = base;
        } else if (total == minn) {
          cheap[idx++] = base;
        }
      }

      for (int i = 0; i < idx; i++) {
        cout << ' ' << cheap[i];
      }

      cout << '\n';
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}