class Solution {
 public:
  int countOrders(int n) {
    if (n == 1) return 1;

    vector<long long> dp(n + 1);
    int modulo = 1e9 + 7;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = (dp[i - 1] * (i * (i + (i - 1)))) % modulo;
    }

    return dp[n];
  }
};