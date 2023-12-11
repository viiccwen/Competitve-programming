class Solution {
 public:
  int findSpecialInteger(vector<int>& arr) {
    unordered_map<int, int> mp;

    for (auto num : arr) {
      mp[num]++;
    }

    int res, MAX_VAL = INT_MIN;
    for (auto [key, val] : mp) {
      if (val > MAX_VAL) {
        res = key;
        MAX_VAL = val;
      }
    }

    return res;
  }
};