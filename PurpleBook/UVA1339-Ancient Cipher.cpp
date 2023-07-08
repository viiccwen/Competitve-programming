#include <bits/stdc++.h>
using namespace std;

vector<int> v1, v2;
string s1, s2;

bool check() {
  v1.assign(26, 0);
  v2.assign(26, 0);

  for (int i = 0; i < s1.size(); i++) {
    v1[s1[i] - 65]++;
    v2[s2[i] - 65]++;
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  for (int i = 0; i < v1.size(); i++) {
    if (v1[i] != v2[i]) return 0;
  }

  return 1;
}

void solve() {
  while (cin >> s1 >> s2) {
    if (s1.size() != s2.size())
      cout << "NO\n";
    else if (check())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
