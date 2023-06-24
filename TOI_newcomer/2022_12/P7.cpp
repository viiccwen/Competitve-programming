#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> ticket(11, vector<int>(11));
vector<bool> visited(11, false);
int a, b;
int ans = INT_MAX;

void dfs(int s, int t, int cost) {
  if (s == t) {
    ans = min(ans, cost);
    return;
  }

  visited[s] = true;

  for (int i = 0; i < N; i++) {
    if (ticket[s][i] != -1 && !visited[i]) {
      visited[i] = true;
      int tmp = cost + ticket[s][i];
      if (cost) tmp -= 50;
      dfs(i, t, tmp);
      visited[i] = false;
    }
  }
}

void solve() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> ticket[i][j];
    }
  }

  cin >> a >> b;
  dfs(a - 1, b - 1, 0);
  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
