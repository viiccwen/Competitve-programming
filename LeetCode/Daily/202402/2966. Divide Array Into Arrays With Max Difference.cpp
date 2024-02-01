class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());

        vector<vector<int>> arr(n / 3, vector<int>(3));
        int idx = 0;

        for(int i=0; i<n; i+=3) {
            if(i + 2 < n && nums[i + 2] - nums[i] <= k) arr[idx++] = { nums[i], nums[i + 1], nums[i + 2] }; 
            else return vector<vector<int>>();
        }

        return arr;
    }
};
/*
1,1,2,2,3,3
*/