class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans(2);
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            if (mp.find(target - nums[i]) == mp.end())
                mp[nums[i]] = i;
            else {
                ans[0] = mp[target - nums[i]];
                ans[1] = i;
            }
        }

        return ans;
    }
};