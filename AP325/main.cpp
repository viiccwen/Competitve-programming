#include <bits/stdc++.h>
using namespace std;

int M, N, ans = 0;

bool check(vector<int> &a, vector<int> &b) {
  for (int i = 0; i < M; i++) {
    if (a[i] ^ b[i] == 0) return false;
  }
  return true;
}

void solve() {
  cin >> M >> N;
  vector<vector<int>> cnt(N, vector<int>(26));
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (auto c : s) cnt[i][c - 'A'] = 1;
  }
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (check(cnt[i], cnt[j])) ans++;
    }
  }

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}