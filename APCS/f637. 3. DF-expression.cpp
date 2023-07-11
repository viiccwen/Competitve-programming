#include <bits/stdc++.h>
using namespace std;
string s;
int N, idx = -1;

int rec(int n) {
  idx++;
  if (s[idx] == '0')
    return 0;
  else if (s[idx] == '1')
    return n * n;
  else {
    int ret = 0;
    for (int i = 0; i < 4; i++) ret += rec(n / 2);
    return ret;
  }
}

void solve() {
  cin >> s >> N;
  cout << rec(N);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}