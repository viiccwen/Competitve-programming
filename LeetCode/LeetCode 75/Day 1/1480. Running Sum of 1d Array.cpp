class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int len = nums.size();

        if (len == 1) return nums;

        vector<int> ans(len);
        ans[0] = nums[0];
        for (int i = 1; i < len; i++)
            ans[i] = ans[i - 1] + nums[i];

        return ans;
    }
};