#include <bits/stdc++.h>
using namespace std;

set<char> st;

void solve() {
  string s = "cbacdcbc";
  string ret;

  for (auto c : s) st.insert(c);

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == *st.begin()) {
      for (int j = i; j < s.size(), st.empty(); j++) {
        auto ite = st.find(s[j]);
        if (ite != st.end()) {
          ret += s[j];
          st.erase(ite);
        }
      }
      return ret;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}