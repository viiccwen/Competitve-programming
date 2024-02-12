class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0; i<n; ++i) mp[nums[i]]++;

        for(auto k : mp) if(k.second > n / 2) return k.first;

        return -1;
    }
};