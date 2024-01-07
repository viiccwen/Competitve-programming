class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<unordered_map<int, int>> dp(n);

        for(int i1=1; i1<n; ++i1) {
            for(int i2=0; i2<i1; ++i2) {
                long long lldiff = static_cast<long long>(nums[i1]) - nums[i2];

                if(lldiff > INT_MAX || lldiff < INT_MIN) continue;

                int diff = static_cast<int>(lldiff);

                dp[i1][diff]++;

                if(dp[i2].count(diff)) {
                    dp[i1][diff] += dp[i2][diff];
                    sum += dp[i2][diff];
                }
            }
        }

        return sum;
    }
};