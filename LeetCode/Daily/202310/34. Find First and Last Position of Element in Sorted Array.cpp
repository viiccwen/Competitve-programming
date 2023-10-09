class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> pos(2, -1);

    auto left = find(nums.begin(), nums.end(), target);
    auto right = find(nums.rbegin(), nums.rend(), target);

    if (left != nums.end()) pos[0] = left - nums.begin();
    if (right != nums.rend())
      pos[1] = nums.size() - (right - nums.rbegin()) - 1;

    return pos;
  }
};