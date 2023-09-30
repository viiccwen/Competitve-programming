#define F first
#define S second
class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    int ans = INT_MIN, n = nums.size();
    vector<pair<int, int>> dp(n, {1, 1});

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          if (dp[i].F < dp[j].F + 1) dp[i].S = 0;

          dp[i].F = max(dp[i].F, dp[j].F + 1);

          if (dp[i].F <= dp[j].F + 1) dp[i].S += dp[j].S;

          ans = max(ans, dp[i].F);
        }
      }
    }

    if (ans == INT_MIN) return n;
    int res = 0;

    for (auto [sub, count] : dp)
      if (sub == ans) res += count;

    return res;
  }
};