#include <bits/stdc++.h>
#define ll long long
using namespace std;

// p2

vector<char> alpha;

void solve() {
  for (int i = 0; i < 26; i++) alpha.push_back(i + 97);

  string s;
  ll t;
  getline(cin, s);
  cin >> t;
  for (ll i = 0; i < s.size(); i++) {
    if (isalpha(s[i])) {
      ll tmp = s[i] + t - 97;
      if (tmp < 0) {
        tmp %= 26;
        tmp = 26 + tmp;
      }
      cout << alpha[tmp];
    } else
      cout << s[i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
