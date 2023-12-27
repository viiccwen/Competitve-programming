class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        char prev_color = colors[0];
        int prev_time = neededTime[0];
        vector<int> dp(n, 0);
        for(int i=1; i<n; ++i) {
            if(colors[i] == prev_color) {
                dp[i] = dp[i - 1] + min(neededTime[i], prev_time);
                prev_time = max(neededTime[i], prev_time);
            } else {
                dp[i] = dp[i - 1];
                prev_color = colors[i];
                prev_time = neededTime[i];
            }
        }   

        return dp[n - 1];
    }
};
// abaaac
// 121423
// 1+2