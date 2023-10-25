class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    int firstday = days[0];
    int lastday = days[n - 1];
    vector<int> dp(lastday + 1, 0);

    for (int i = 0; i < n; i++) dp[days[i]] = 1;

    for (int i = 1; i <= lastday; i++) {
      if (dp[i] != 1)
        dp[i] = dp[i - 1];
      else {
        int oneday = dp[max(0, i - 1)] + costs[0];
        int sevenday = dp[max(0, i - 7)] + costs[1];
        int thirtyday = dp[max(0, i - 30)] + costs[2];
        dp[i] = min(oneday, min(sevenday, thirtyday));
      }
    }

    return dp[lastday];
  }
};