class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= target; i++) {
      for (auto val : nums) {
        if (i >= val) dp[i] += dp[i - val];
      }
    }

    return dp[target];
  }
};