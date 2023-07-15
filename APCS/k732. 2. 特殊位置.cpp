#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define x first
#define y second
int N, M, cnt = 0;
vector<vector<int>> mat;
vector<pii> record;

bool check(int y, int x) {
  pii start = {x - mat[y][x], y - mat[y][x]};
  pii end = {x + mat[y][x], y + mat[y][x]};

  if (start.y < 0) start.y = 0;
  if (start.x < 0) start.x = 0;
  if (end.y >= N) end.y = N - 1;
  if (end.x >= M) end.x = M - 1;

  int sum = 0;

  for (int i = start.y; i <= end.y; i++) {
    for (int j = start.x; j <= end.x; j++) {
      if (abs(i - y) + abs(j - x) <= mat[y][x]) sum += mat[i][j];
    }
  }

  if (sum % 10 == mat[y][x]) return 1;
  return 0;
}

void solve() {
  cin >> N >> M;
  mat.assign(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) cin >> mat[i][j];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (check(i, j)) {
        record.push_back({i, j});
        cnt++;
      }
    }
  }

  cout << cnt << '\n';
  for (auto k : record) cout << k.x << ' ' << k.y << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}