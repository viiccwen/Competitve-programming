class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (auto ite : nums) mp[ite]++;

    vector<int> vec;
    int n = nums.size();
    for (auto [key, val] : mp)
      if (val > n / 3) vec.push_back(key);

    return vec;
  }
};