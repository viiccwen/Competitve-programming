class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int repete, miss = -1;
        sort(nums.begin(), nums.end());

        for(int i=0, prev=0; i<n; ++i) {
            if(prev == nums[i]) repete = nums[i];
            if(nums[i] - prev > 1) miss = nums[i] - 1;
            prev = nums[i];
        }

        if(miss == -1) miss = n;

        return {repete, miss};
    }
};