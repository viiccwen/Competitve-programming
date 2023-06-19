#include <bits/stdc++.h>
using namespace std;

bool Mirror(string &s) {
  int len = s.size();
  unordered_map<char, char> mp = {
      {'A', 'A'}, {'E', '3'}, {'H', 'H'}, {'I', 'I'}, {'J', 'L'}, {'L', 'J'},
      {'M', 'M'}, {'O', 'O'}, {'S', '2'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'},
      {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'}, {'1', '1'}, {'2', 'S'},
      {'3', 'E'}, {'5', 'Z'}, {'8', '8'}};

  for (int i = 0; i < len / 2; i++) {
    if (!mp.count(s[i]) || !mp.count(s[len - i - 1]) ||
        mp[s[i]] != s[len - i - 1])
      return false;
  }

  if (len % 2 == 1) {
    if (!mp.count(s[len / 2]) || s[len / 2] != mp[s[len / 2]]) return false;
  }

  return true;
}

bool Palindrome(string &s) {
  int len = s.size();
  for (int i = 0; i < len / 2; i++) {
    if (s[i] != s[len - i - 1]) return false;
  }
  return true;
}

void solve() {
  string s;
  while (cin >> s) {
    bool f1 = Palindrome(s), f2 = Mirror(s);
    if (!f1 && !f2)
      cout << s << " -- is not a palindrome.\n\n";
    else if (f1 && !f2)
      cout << s << " -- is a regular palindrome.\n\n";
    else if (!f1 && f2)
      cout << s << " -- is a mirrored string.\n\n";
    else if (f1 && f2)
      cout << s << " -- is a mirrored palindrome.\n\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
