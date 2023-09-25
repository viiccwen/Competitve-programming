class Solution {
 public:
  char findTheDifference(string s, string t) {
    unordered_map<char, int> mp;
    for (auto c : s) mp[c]++;
    for (auto c : t) {
      if (mp.count(c) && mp[c] > 0)
        mp[c]--;
      else
        return c;
    }
    return t[0];
  }
};