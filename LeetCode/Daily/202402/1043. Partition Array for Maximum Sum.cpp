class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for(int i=0; i<n; ++i) {
            int cur_max = 0, cur_sum = 0;

            for(int j=i; j>=max(0, i - k + 1) ; --j) {
                cur_max = max(cur_max, arr[j]);

                int cur_part = cur_max * (i - j + 1) + dp[j];
                
                cur_sum = max(cur_sum, cur_part);
            }

            dp[i + 1] = cur_sum;
        }   

        return dp[n];     
    }
};