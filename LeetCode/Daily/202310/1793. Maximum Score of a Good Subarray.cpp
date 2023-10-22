class Solution {
 public:
  int maximumScore(vector<int>& nums, int k) {
    int maximum = nums[k];
    int minimum = nums[k];
    int left = k;
    int right = k;
    int n = nums.size();

    while (left > 0 || right < n - 1) {
      if (!left || (right < n - 1 && nums[right + 1] > nums[left - 1]))
        right++;
      else
        left--;

      minimum = min(minimum, min(nums[right], nums[left]));
      maximum = max(maximum, minimum * (right - left + 1));
    }

    return maximum;
  }
};