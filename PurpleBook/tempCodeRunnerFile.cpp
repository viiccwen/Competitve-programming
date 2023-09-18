#include <bits/stdc++.h>
using namespace std;

char c;
string str, s;
set<string> st;
void solve() {
  while (getline(cin, str)) {
    for (int i = 0; i < str.size(); i++) {
      if (isalpha(str[i])) {
        if (isupper(str[i])) str[i] = tolower(str[i]);
        s += str[i];
      } else if (!s.empty()) {
        st.insert(s);
        s.clear();
      }
    }
  }

  for (auto i : st) cout << i << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}