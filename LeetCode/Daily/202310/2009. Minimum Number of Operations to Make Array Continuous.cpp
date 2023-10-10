class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int ans = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
      int s = nums[i], e = s + n - 1;
      auto ite = upper_bound(nums.begin(), nums.end(), e);

      int idx = ite - nums.begin();
      ans = min(ans, n - (idx - i));
    }

    return ans;
  }
};