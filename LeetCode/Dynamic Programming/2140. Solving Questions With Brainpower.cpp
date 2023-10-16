class Solution {
 public:
  long long mostPoints(vector<vector<int>>& q) {
    int n = q.size();
    vector<long long> dp(n);

    for (int i = n - 1; i >= 0; i--) {
      long long take = q[i][0];
      long long not_take = 0;

      if (i + q[i][1] + 1 < n) take += dp[i + q[i][1] + 1];
      if (i + 1 < n) not_take = dp[i + 1];

      dp[i] = max(take, not_take);
    }

    return dp[0];
  }
};