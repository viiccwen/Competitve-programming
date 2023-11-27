class Solution {
 public:
  int knightDialer(int n) {
    if (n <= 2) return 10 * n;

    const int MOD = 1e9 + 7;
    vector<vector<int>> keypad{{4, 6}, {6, 8},    {7, 9}, {4, 8}, {0, 3, 9},
                               {},     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

    vector<vector<int>> dp(10, vector<int>(n + 1, 0));

    for (int i = 0; i < 10; i++) dp[i][1] = 1;

    for (int j = 2; j <= n; j++) {
      for (int i = 0; i < 10; i++) {
        for (int k = 0; k < keypad[i].size(); k++) {
          dp[i][j] = (dp[i][j] + dp[keypad[i][k]][j - 1]) % MOD;
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) ans = (ans + dp[i][n]) % MOD;

    return ans;
  }
};