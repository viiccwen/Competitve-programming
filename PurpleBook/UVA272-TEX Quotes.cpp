#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int cnt = 0;
  while (getline(cin, s)) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '"' && !cnt) {
        s.erase(s.begin() + i);
        s.insert(i, "``");
        cnt++;
      } else if (s[i] == '"' && cnt) {
        s.erase(s.begin() + i);
        s.insert(i, "''");
        cnt ^= cnt;
      }
    }
    for (auto c : s) cout << c;
    cout << '\n';
  }
}