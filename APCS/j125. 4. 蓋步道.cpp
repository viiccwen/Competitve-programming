#include <bits/stdc++.h>
#define SIZE 350
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define f first
#define s second
using namespace std;

int N, steps;
vvi height(SIZE, vector<int>(SIZE, 0));
vvi visit(SIZE, vector<int>(SIZE, 0));
pii dir[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void bfs(int dif) {
  queue<pii> q;
  q.push({1, 1});

  while (!q.empty()) {
    int x = q.front().f, y = q.front().s;
    q.pop();

    if (x < 1 || y < 1 || x > N || y > N) continue;

    for (int d = 0; d < 4; d++) {
      int nx = x + dir[d].f, ny = y + dir[d].s;
      if (!visit[nx][ny] && abs(height[nx][ny] - height[x][y]) <= dif) {
        q.push({nx, ny});
        visit[nx][ny] = visit[x][y] + 1;
      }
    }
  }
}

void solve() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) cin >> height[i][j];
  }

  int L = 0, R = 1e6;
  while (L < R) {
    int M = (L + R) >> 1;

    for (auto &i : visit) i.assign(SIZE, 0);

    bfs(M);

    if (visit[N][N]) {
      R = M;
      steps = visit[N][N];
    } else
      L = M + 1;
  }

  cout << L << '\n' << steps;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}