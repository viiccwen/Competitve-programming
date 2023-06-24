#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
bool check = 1;

void dfs(string s, int tmp) {
  if (s == "9" && tmp > 0) {
    cnt = tmp;
    return;
  }

  int sum = 0;
  for (int i = 0; i < s.size(); i++) sum += s[i] - '0';

  if (sum % 9 == 0)
    dfs(to_string(sum), tmp + 1);
  else {
    check = 0;
    return;
  }
}

void solve(string N) {
  cnt ^= cnt;
  check = 1;

  dfs(N, 0);
  if (check)
    cout << N << " is a multiple of 9 and has 9-degree " << cnt << ".\n";
  else
    cout << N << " is not a multiple of 9.\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string N;
  while (cin >> N && N != "0") solve(N);
}