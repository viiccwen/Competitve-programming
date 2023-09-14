class Solution {
 public:
  int rob(vector<int>& nums) {
    int len = nums.size();

    vector<int> dp(len + 1, 0);
    dp[len] = 0, dp[len - 1] = nums[len - 1];
    for (int i = len - 2; i >= 0; i--) {
      dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
    }

    return dp[0];
  }
};