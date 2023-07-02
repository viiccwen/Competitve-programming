#include <bits/stdc++.h>
#define SIZE 100001
using namespace std;

vector<vector<int>> tree(SIZE, vector<int>(0));
vector<int> depth;
int first_node = 0;
int max_depth = 0;

void dfs(int node, int fnd) {
  for (auto i : tree[node]) {
    if (i != fnd) {
      depth[i] = depth[node] + 1;
      dfs(i, node);
    }
  }
}

void solve(int &n) {
  depth.assign(SIZE, 0);
  for (int i = 0; i < n; i++) tree[i].clear();

  for (int i = 0, a, b; i < n - 1; i++) {
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  dfs(0, -1);
  max_depth = 0;
  for (int i = 0; i < n; i++) {
    if (depth[i] > max_depth) {
      max_depth = depth[i];
      first_node = i;
    }
  }

  depth.assign(SIZE, 0);
  dfs(first_node, -1);
  max_depth = 0;
  for (int i = 0; i < n; i++) max_depth = max(max_depth, depth[i]);

  cout << max_depth << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    solve(n);
  }
}