class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> pos(2, -1);

    auto left = lower_bound(nums.begin(), nums.end(), target);
    auto right = upper_bound(nums.begin(), nums.end(), target);

    if (left != nums.end() && *left == target) {
      pos[0] = left - nums.begin();
      pos[1] = right - nums.begin() - 1;
    }

    return pos;
  }
};