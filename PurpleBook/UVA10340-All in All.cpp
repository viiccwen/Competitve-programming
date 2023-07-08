#include <bits/stdc++.h>
using namespace std;
string ttr, str;

bool check() {
  int tidx = 0;
  int tlen = ttr.size(), slen = str.size();

  if (tlen > slen) return 0;

  for (int i = 0; i < slen; i++) {
    if (ttr[tidx] == str[i]) tidx++;
    if (tidx == tlen) return 1;
  }

  return 0;
}

void solve() {
  while (cin >> ttr >> str) {
    if (check())
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
