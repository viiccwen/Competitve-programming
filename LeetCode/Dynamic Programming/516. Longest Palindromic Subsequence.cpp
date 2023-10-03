class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    string t = s;
    reverse(t.begin(), t.end());

    const int m = s.size();
    const int n = t.size();
    vector<vector<int>> dp(2, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (s[i - 1] == t[j - 1])
          dp[i & 1][j] = 1 + dp[(i - 1) & 1][j - 1];
        else
          dp[i & 1][j] = max(dp[(i - 1) & 1][j], dp[i & 1][j - 1]);
      }
    }
    return dp[m & 1][n];
  }
};