class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int targetSum = -x;
    for (int num : nums) targetSum += num;

    if (targetSum == 0) return nums.size();

    int maxLength = -1, currentSum = 0, left = 0;

    for (int right = 0; right < nums.size(); right++) {
      currentSum += nums[right];

      while (currentSum > targetSum && left <= right)
        currentSum -= nums[left++];

      if (currentSum == targetSum) maxLength = max(maxLength, right - left + 1);
    }

    return (maxLength != -1) ? nums.size() - maxLength : -1;
  }
};