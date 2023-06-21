#include <bits/stdc++.h>
using namespace std;

set<string> dict = {"the", "a",  "an", "in",  "on", "at", "of",
                    "for", "by", "to", "and", "or", "but"};

stringstream ss;

int Count(string s) {
  int cnt = 0;
  ss << s;
  while (ss >> s) cnt++;
  ss.str("");
  ss.clear();
  return cnt;
}

void solve() {
  stringstream ss;
  string s, ans;
  ans = "";
  bool flag = 0;

  getline(cin, s);
  int cnt = Count(s);

  ss << s;
  int ind = 0;
  while (ss >> s) {
    for (int i = 0; i < s.size(); i++) s[i] = tolower(s[i]);
    if (ind == 0) {
      s[0] = toupper(s[0]);
      ans += s + ' ';
    } else if (ind == cnt - 1) {
      s[0] = toupper(s[0]);
      ans += s;
    } else if (dict.count(s)) {
      ans += s + ' ';
    } else {
      s[0] = toupper(s[0]);
      ans += s + ' ';
    }
    ind++;
  }

  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}