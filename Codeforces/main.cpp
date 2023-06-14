#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, sum = 0;
  string s;
  cin >> n;
  while (n--) {
    cin >> s;
    if (s[1] == '+')
      sum++;
    else
      sum--;
  }
  cout << sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}