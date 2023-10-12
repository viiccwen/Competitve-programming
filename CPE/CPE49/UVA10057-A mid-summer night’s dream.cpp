#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  while (cin >> N) {
    vector<int> num(N);

    for (auto &n : num) cin >> n;

    sort(num.begin(), num.end());

    int f_mid, s_mid;
    if (N % 2)
      f_mid = s_mid = num[N / 2];
    else {
      f_mid = num[N / 2 - 1];
      s_mid = num[N / 2];
    }

    int eqal_cnt = 0, posb_cnt = 0;
    for (auto i : num)
      if (f_mid == i || s_mid == i) eqal_cnt++;

    posb_cnt = (N % 2) ? 1 : s_mid - f_mid + 1;

    cout << f_mid << ' ' << eqal_cnt << ' ' << posb_cnt << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}