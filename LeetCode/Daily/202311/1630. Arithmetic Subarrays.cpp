class Solution {
 public:
  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
                                        vector<int>& r) {
    int n = nums.size();
    int m = l.size();
    vector<bool> ans(m, true);

    for (int i = 0; i < m; i++) {
      vector<int> tmp(nums.begin() + l[i], nums.begin() + r[i] + 1);

      if (tmp.size() <= 2) {
        ans[i] = true;
        continue;
      }

      sort(tmp.begin(), tmp.end());
      int dif = tmp[1] - tmp[0];

      for (int j = 2; j < tmp.size(); j++) {
        if (tmp[j] - tmp[j - 1] != dif) {
          ans[i] = false;
          break;
        }
      }
    }

    return ans;
  }
};