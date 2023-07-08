#include <bits/stdc++.h>
using namespace std;

int digitsum(int k) {
  int sum = k;
  while (k) {
    sum += k % 10;
    k /= 10;
  }
  return sum;
}

void solve() {
  int N, k;
  cin >> N;
  while (N--) {
    int ans = -1;
    cin >> k;

    for (int i = k - 45, tmp; i < k; i++) {
      if (i <= 0) continue;
      tmp = digitsum(i);
      if (k == tmp) {
        ans = i;
        break;
      }
    }

    if (ans == -1)
      cout << "0\n";
    else
      cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
