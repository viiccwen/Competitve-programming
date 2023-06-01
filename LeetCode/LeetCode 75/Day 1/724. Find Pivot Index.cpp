class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        int sum_total = 0;
        int sum_left = 0, sum_right = 0;

        for (int i = 0; i < len; i++)
            sum_total += nums[i];

        if (!(sum_total - nums[0]))
            return 0;

        for (int i = 0; i < len; i++) {
            if (sum_left == sum_total - sum_left - nums[i]) return i; // 用總和扣掉元素
            sum_left += nums[i];
        }

        return -1;
    }
};