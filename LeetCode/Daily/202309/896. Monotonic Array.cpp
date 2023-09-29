class Solution {
 public:
  bool isMonotonic(vector<int>& nums) {
    int len = nums.size();
    int dir = 0;

    for (int i = 1; i < len; i++) {
      if (nums[i] > nums[i - 1]) {
        if (!dir)
          dir = 1;
        else if (dir == -1)
          return false;
      } else if (nums[i] < nums[i - 1]) {
        if (!dir)
          dir = -1;
        else if (dir == 1)
          return false;
      }
    }

    return true;
  }
};