class Solution {
 public:
  int reductionOperations(vector<int>& nums) {
    unordered_map<int, int> mp;

    for (auto num : nums) mp[num]++;

    sort(nums.begin(), nums.end());

    int idx = 0, minn = nums[0], n = nums.size();
    int sum = 0, prev = INT_MIN;

    while (idx < n && nums[idx] == minn) idx++;

    if (idx >= n) return 0;

    for (int i = n - 1; i >= idx; i--) {
      if (nums[i] == prev) continue;

      sum += (n - 1 - i) + mp[nums[i]];
      prev = nums[i];
    }

    return sum;
  }
};
