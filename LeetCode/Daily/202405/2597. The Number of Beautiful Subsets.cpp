class Solution {
public:
    void helper(vector<int>& nums, unordered_map<int, int>& mp, int& k, int& sum, int idx) {
        if(idx == nums.size()) {
            sum++;
            return;
        }

        int num = nums[idx];
        
        if(mp.find(num - k) == mp.end() && 
            mp.find(num + k) == mp.end()) {
                mp[num]++;
                helper(nums, mp, k, sum, idx + 1);
                mp[num]--;
                if(mp[num] == 0) mp.erase(num);
            }

            helper(nums, mp, k, sum, idx + 1);
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> mp;
        helper(nums, mp, k, sum, 0);
        return sum - 1;
    }
};