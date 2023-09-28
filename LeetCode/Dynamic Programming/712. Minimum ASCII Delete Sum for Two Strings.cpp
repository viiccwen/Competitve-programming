class Solution {
 public:
  int minimumDeleteSum(string s1, string s2) {
    int r = s1.size(), c = s2.size();
    vector<vector<int>> dp(r + 1, vector<int>(c + 1, 0));

    for (int i = 1; i <= r; i++) dp[i][0] = dp[i - 1][0] + s1[i - 1];
    for (int i = 1; i <= c; i++) dp[0][i] = dp[0][i - 1] + s2[i - 1];

    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        if (s1[i - 1] == s2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = min(dp[i][j - 1] + s2[j - 1], dp[i - 1][j] + s1[i - 1]);
      }
    }

    return dp[r][c];
  }
};