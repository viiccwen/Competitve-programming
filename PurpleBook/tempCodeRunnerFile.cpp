#include <bits/stdc++.h>
using namespace std;

string s, circle;
int len;

bool check(int idx) {
  for (int i = idx, k = 0; i < circle.size(); i++) {
    if (circle[k++] != s[i]) return 0;
  }
  return 1;
}

void solve() {
  circle.clear();
  cin >> s;
  len = s.size();

  for (int i = 0; i < len; i++) {
    if (circle.empty())
      circle += s[i];
    else if (circle[0] != s[i])
      circle += s[i];
    else {
      if (check(i)) {
        break;
      } else {
        circle += s[i];
      }
    }
  }
  cout << circle.size() << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  while (N--) solve();
}
