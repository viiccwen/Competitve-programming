class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        if(nums.size() == 1) return nums;

        int n = nums.size();
        vector<int> ans(n);
        vector<int> presum(n);

        presum[0] = nums[0];
        for(int i=1;i<n;i++) presum[i] = presum[i-1] + nums[i];

        for(int i=0;i<n;i++) {
            ans[i] = nums[i] * i - (i ? presum[i-1] : 0) + (presum[n-1] - presum[i]) - nums[i] * (n - i - 1);
        }
        
        return ans;
    }
};
/*
nums[2]-nums[0] + nums[2]-nums[1] + nums[3]-nums[2] + nums[4]-nums[2]

= nums[i]*i - presum[i-1] + (presum[n-1] - presum[i]) - nums[i]

nums[2] * 2 - (nums[0] + nums[1]) + (nums[3]+nums[4]) - nums[2]*(n-i-1)
nums[i] * i - (prefix_sum[i-1]) + (prefix_sum[n-1] - prefix_sum[i]) - nums[i] * (n-i-1)

*/