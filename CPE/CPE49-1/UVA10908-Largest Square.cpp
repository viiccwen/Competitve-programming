#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int t, r, c, q;
pair<int, int> dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<vector<char>> v;

bool check(int x, int y) {
  if (!(x >= 0 && x < r && y >= 0 && y < c)) return false;
  return true;
}

bool bfs(int x, int y, char chr, int times) {
  if (!check(x, y)) return false;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j <= times; j++) {
      if (j) {
        x += dir[i].f;
        y += dir[i].s;
      }
      if (!(check(x, y) && v[x][y] == chr)) return false;
    }
  }
  return true;
}

int cal(int x, int y, char chr) {
  int cnt = 1, modx = -1, mody = -1, times = 2;
  while (bfs(x + modx, y + mody, chr, times)) {
    cnt = times + 1;
    modx--;
    mody--;
    times += 2;
  }
  return cnt;
}

void solve() {
  cin >> t;
  while (t--) {
    cin >> r >> c >> q;

    v.resize(r);
    for (int i = 0; i < r; i++) v[i].resize(c);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> v[i][j];
      }
    }

    cout << r << ' ' << c << ' ' << q << '\n';
    while (q--) {
      int x, y;
      cin >> x >> y;
      cout << cal(x, y, v[x][y]) << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}