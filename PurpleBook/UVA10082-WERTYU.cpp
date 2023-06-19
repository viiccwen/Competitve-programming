#include <bits/stdc++.h>
using namespace std;

void solve() {
  string alpha_map = " VXSWDFGUHJKNBIO EARYCQZT ";
  string digit_map = "9`12345678";
  unordered_map<char, char> mp = {
      {'=', '-'},  {'-', '0'}, {'\\', ']'}, {'[', 'P'}, {']', '['},
      {'\'', ';'}, {';', 'L'}, {'/', '.'},  {'.', ','}, {',', 'M'}};

  string s, ans;
  while (getline(cin, s)) {
    ans = "";
    for (int i = 0; i < s.size(); i++) {
      if (isalpha(s[i]))
        ans += alpha_map[s[i] - 'A'];

      else if (isdigit(s[i]))
        ans += digit_map[s[i] - '0'];

      else if (s[i] == ' ')
        ans += ' ';

      else
        ans += mp[s[i]];
    }
    cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}