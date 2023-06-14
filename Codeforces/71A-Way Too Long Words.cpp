#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  while (n--) {
    string s;
    cin >> s;

    int len = s.size();
    if (len <= 10)
      cout << s << '\n';
    else
      cout << s[0] << len - 2 << s[len - 1] << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}