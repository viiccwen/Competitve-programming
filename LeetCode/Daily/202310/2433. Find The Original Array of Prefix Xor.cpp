class Solution {
 public:
  vector<int> findArray(vector<int>& pref) {
    int n = pref.size();
    if (n == 1) return pref;

    vector<int> res(n);
    res[0] = pref[0];

    for (int i = 1, cur = pref[0], now = pref[0]; i < n; i++) {
      cur ^= pref[i];
      res[i] = cur;
      now ^= cur;
      cur = now;
    }

    return res;
  }
};