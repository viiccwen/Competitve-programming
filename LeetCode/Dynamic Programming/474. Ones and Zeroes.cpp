class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    int k = strs.size();
    vector<vector<vector<int>>> dp(
        k + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

    for (int i = 1; i <= k; i++) {
      int zeros = 0, ones = 0;
      for (char c : strs[i - 1]) {
        if (c == '0')
          zeros++;
        else
          ones++;
      }

      for (int j = 0; j <= m; j++) {
        for (int k = 0; k <= n; k++) {
          dp[i][j][k] = dp[i - 1][j][k];
          if (j >= zeros && k >= ones) {
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1);
          }
        }
      }
    }

    return dp[k][m][n];
  }
};