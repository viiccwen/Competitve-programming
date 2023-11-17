class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxx = INT_MIN;

    for (int i = 0; i < n / 2; i++) maxx = max(maxx, nums[i] + nums[n - i - 1]);

    return maxx;
  }
};

/*
2 3 3 5
1 1 1 2 4 4 5 5 5 5
*/