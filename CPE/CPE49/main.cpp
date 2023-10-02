#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  while (getline(cin, s)) {
    int tmp;
    for (auto c : s) {
      if (isdigit(c))
        tmp = c - '0';
      else if (isupper(c))
        tmp = c - 'A' + 10;
      else if (islower(c))
        tmp = c - 'a' + 36;
      else
        continue;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}