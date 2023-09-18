#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

string s;
int idx = 0;

LL rec(int &head, int &tail) {
  LL total = 0, t;
  head = tail = -1;

  while (1) {
    if (idx >= s.size()) return total;

    if (s[idx] == 'T') {
      t = stoi(s.substr(idx + 1, 2));
      idx += 3;
      if (tail < 0)
        head = t;
      else
        total += abs(tail - t);
      tail = t;
    } else if (s[idx] == 'L') {
      t = stoi(s.substr(idx + 1, 1));
      idx += 2;
      int h, e;
      LL cost = rec(h, e);
      if (tail < 0)
        head = h;
      else
        total += abs(tail - h);
      tail = e;
      total += cost * t + abs(h - e) * (t - 1);
    } else {
      idx++;
      return total;
    }
  }
}

void solve() {
  int i, j;
  cin >> s;
  LL ans = rec(i, j);
  ans += abs(10 - i);
  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}