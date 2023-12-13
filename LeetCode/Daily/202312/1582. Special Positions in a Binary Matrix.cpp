class Solution {
 public:
  bool col(int &n, int &m, int &x, int &y, vector<vector<int>> &mat) {
    for (int i = 0; i < m; i++)
      if (i != y && mat[x][i]) return false;

    return true;
  }
  bool row(int &n, int &m, int &x, int &y, vector<vector<int>> &mat) {
    for (int i = 0; i < n; i++)
      if (i != x && mat[i][y]) return false;

    return true;
  }
  int numSpecial(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] && row(n, m, i, j, mat) && col(n, m, i, j, mat)) ans++;
      }
    }

    return ans;
  }
};