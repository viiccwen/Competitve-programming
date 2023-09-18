#include <bits/stdc++.h>
using namespace std;

char c;
string str, s;
set<string> st;
void solve() {
  while (getline(cin, str)) {
    for (auto &ch : str) {
      if (isalpha(ch))
        ch = tolower(ch);
      else
        ch = ' ';
    }
    s += " " + str;
  }

  stringstream input(s);
  while (input >> str) st.insert(str);
  for (auto p : st) cout << p << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}