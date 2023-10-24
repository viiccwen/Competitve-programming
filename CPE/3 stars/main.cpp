#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& child, vector<int>& marble, int root) {
  if (child[root].size() == 0) return abs(marble[root] - 1);

  int sub_sum = 0;

  for (int i = 0; i < child[root].size(); i++) {
    sub_sum += dfs(child, marble, child[root][i]);
  }

  return sub_sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  while (cin >> n && n != 0) {
    vector<vector<int>> child(n + 1);
    vector<bool> is_root(n + 1, true);
    vector<int> marble(n + 1, 0);
    int root = -1;

    for (int i = 1; i <= n; i++) {
      int tmp, marble_num, offspring;
      cin >> tmp >> marble_num >> offspring;
      marble[i] = marble_num;

      for (int j = 1; j <= offspring; j++) {
        int vertex;
        cin >> vertex;
        child[tmp].push_back(vertex);
        is_root[vertex] = false;
      }
    }

    for (int i = 1; i <= n; i++) {
      if (is_root[i]) {
        root = i;
        break;
      }
    }

    cout << abs(marble[root] - 1) + dfs(child, marble, root) << '\n';
  }
}
/*
9
1 2 3 2 3 4
2 1 0
3 0 2 5 6
4 1 3 7 8 9
5 3 0
6 0 0
7 0 0
8 2 0
9 0 0
9
1 0 3 2 3 4
2 0 0
3 0 2 5 6
4 9 3 7 8 9
5 0 0
6 0 0
7 0 0
8 0 0
9 0 0
9
1 0 3 2 3 4
2 9 0
3 0 2 5 6
4 0 3 7 8 9
5 0 0
6 0 0
7 0 0
8 0 0
9 0 0
0
*/