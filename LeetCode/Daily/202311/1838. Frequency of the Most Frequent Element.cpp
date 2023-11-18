class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    long sum = 0, maxx = 0;
    for (long int i = 0, j = 0; i < n; i++) {
      sum += nums[i];

      while ((i - j + 1) * nums[i] - sum > k) {
        sum -= nums[j];
        j++;
      }

      maxx = max(maxx, i - j + 1);
    }

    return maxx;
  }
};