class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    for (auto num : nums) {
      if (num % 2 != 0)
        break;
      else
        left++;
    }

    while (left < right) {
      if (!(nums[right] % 2) && !(nums[left] % 2))
        left++;
      else if (!(nums[right] % 2))
        swap(nums[left++], nums[right--]);
      else
        right--;
    }

    return nums;
  }
};

/*
vector<int> vec, odd;

for(auto num : nums) {
    if(num % 2) vec.push_back(num);
    else odd.push_back(num);
}

for(auto num : odd) vec.push_back(num);

reverse(vec.begin(), vec.end());

return vec;
*/