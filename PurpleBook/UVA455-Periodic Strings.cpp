#include <bits/stdc++.h>
using namespace std;

string s, circle;
int len;

void solve() {
  cin >> s;
  len = s.size();
  int t = 1;

  for (int i = 1; i < len; i++) {
    circle = "";
    if (s == s.substr(i, len - 1) + s.substr(0, i)) {
      break;
    } else {
      t++;
    }
  }
  cout << t;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  while (N--) {
    solve();
    if (!N)
      cout << "\n";
    else
      cout << "\n\n";
  }
}
