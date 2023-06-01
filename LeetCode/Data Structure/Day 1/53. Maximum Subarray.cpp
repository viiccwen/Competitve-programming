class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int cur = 0, result = -1e9;

        if (len == 1) return nums[0];

        for (int i = 0; i < len; i++) {
            cur += nums[i];
            if (cur < nums[i]) cur = nums[i];
            if (cur > result) result = cur;
        }

        return result;
    }
};