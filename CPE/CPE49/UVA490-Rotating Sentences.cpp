
#include <bits/stdc++.h>
using namespace std;

void solve() {
  vector<string> vec(101);
  int idx = 0, maximum = 0;

  while (getline(cin, vec[idx])) {
    int len = vec[idx].size();
    maximum = max(maximum, len);
    idx++;
  }

  for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < vec[i].size(); j++) {
      if (vec[i][j] == ' ') vec[i][j] = '\0';
    }
  }

  for (int i = 0; i < maximum; i++) {
    string cur = "";
    for (int j = idx - 1; j >= 0; j--) {
      if (vec[j].size() > i)
        cur += vec[j][i];
      else
        cur += ' ';
    }

    int end = cur.size() - 1;

    while (cur[end] == ' ') end--;

    for (int i = 0; i <= end; i++) {
      if (cur[i] == '\0')
        cout << ' ';
      else
        cout << cur[i];
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
