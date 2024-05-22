class Solution {
public:
    int sum = 0;
    void recursive(vector<int>& nums, int cur, int idx) {
        if(idx == nums.size()) {
            sum += cur;
            return;
        }
        recursive(nums, cur, idx + 1);
        recursive(nums, cur ^ nums[idx], idx + 1);
    }
    int subsetXORSum(vector<int>& nums) {
        recursive(nums, 0, 0);
        return sum;
    }
};