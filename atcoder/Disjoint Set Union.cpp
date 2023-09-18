#include <bits/stdc++.h>
using namespace std;

vector<int> boss(200000);
int f, u, v;

int find_root(int x) {
  if (boss[x] == x) return x;

  int root = find_root(boss[x]);
  boss[x] = root;
  return root;
}

void connect(int x, int y) {
  int root_x = find_root(x);
  int root_y = find_root(y);
  boss[root_x] = root_y;
}

void solve() {
  int N, Q;
  cin >> N >> Q;
  for (int i = 0; i < boss.size(); i++) boss[i] = i;
  while (Q--) {
    cin >> f >> u >> v;
    if (!f) {
      connect(u, v);
    } else {
      if (find_root(u) == find_root(v))
        cout << "1\n";
      else
        cout << "0\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}