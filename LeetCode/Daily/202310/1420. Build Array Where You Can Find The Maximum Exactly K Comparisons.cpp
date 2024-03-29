class Solution {
  typedef long long LL;

 public:
  int numOfArrays(int n, int m, int k) {
    int mod = 1e9 + 7;
    vector<vector<vector<LL>>> dp(
        n + 1, vector<vector<LL>>(m + 1, vector<LL>(k + 1, 0)));

    for (int i = 0; i <= m; i++) dp[1][i][1] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        for (int t = 1; t <= k; t++) {
          LL s = 0;
          s = (s + j * dp[i - 1][j][t]) % mod;

          for (int x = 1; x < j; x++) s = (s + dp[i - 1][x][t - 1]) % mod;

          dp[i][j][t] = (dp[i][j][t] + s) % mod;
        }
      }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) ans = (ans + dp[n][i][k]) % mod;

    return ans;
  }
};

/*
n = length
m = number limit 1 ~ m
k = cnt
*/