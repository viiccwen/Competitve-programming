class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), maxx = 1, next_num = -1;
        
        vector<int> dp(n, 1);
        vector<int> vec;

        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                if(nums[j] % nums[i] == 0 && dp[j] < dp[i] + 1) {
                    dp[j] = dp[i] + 1;
                    maxx = max(maxx, dp[j]);
                }
            }
        }

        for(int i=n-1; i>=0; --i) {
            if(dp[i] == maxx && (next_num == -1 || next_num % nums[i] == 0) ) {
                vec.emplace_back(nums[i]);
                maxx--;
                next_num = nums[i];
            }
        }

        return vec;
    }
};