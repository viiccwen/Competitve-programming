class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            long long sum = 0;
            for (int j = 0; j <= k; ++j) {
                sum += dp[i - 1][j];
                if (j >= i) {
                    sum -= dp[i - 1][j - i];
                }
                dp[i][j] = (sum + MOD) % MOD;
            }
        }

        return dp[n][k];
    }
};

/*
  0  1  2  3
0 1
1 1  0  0  0
2 1  1  0  0
3 1  2  2  1

*/