class Solution {
 public:
  int longestSubsequence(vector<int>& arr, int dif) {
    int ans = 0;
    unordered_map<int, int> mp;
    for (auto k : arr) {
      int cnt = 0;
      if (mp.count(k - dif)) cnt = mp[k - dif];

      mp[k] = 1 + cnt;
      ans = max(ans, mp[k]);
    }

    return ans;
  }
};