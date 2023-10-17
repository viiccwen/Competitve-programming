class Solution {
 public:
  int change(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
      int minimum = INT_MAX;
      for (int j = 0; j < coins.size(); j++) {
        int cur = i - coins[j];
        if (cur >= 0) {
          int ans = dp[cur];
          if (ans != INT_MAX) minimum = min(minimum, 1 + ans);
        }
      }
      dp[i] = minimum;
    }

    return dp[amount];
  }
  int coinChange(vector<int>& coins, int amount) {
    int surplus = change(coins, amount);
    return surplus == INT_MAX ? -1 : surplus;
  }
};