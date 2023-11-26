class Solution {
 public:
  static bool cmp(int& a, int& b) { return a > b; }
  int largestSubmatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] != 0 && i) mat[i][j] += mat[i - 1][j];
      }

      vector<int> cur = mat[i];
      sort(cur.begin(), cur.end(), cmp);

      for (int k = 0; k < m; k++) ans = max(ans, cur[k] * (k + 1));
    }

    return ans;
  }
};
