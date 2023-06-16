#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  bool flag = 0;
  while (getline(cin, s)) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '"' && !flag) {
        s.erase(s.begin() + i);
        s.replace(s.begin() + i, s.begin() + i, "``");
        flag = 1;
      } else if (s[i] == '"' && flag) {
        s.erase(s.begin() + i);
        s.replace(s.begin() + i, s.begin() + i, "''");
        flag = 0;
      }
    }
    cout << s << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}