class Solution {
 public:
  bool isSubsequence(string s, string t) {
    if (s == "") return true;
    int n = s.size(), m = t.size();
    int j = 0;
    for (int i = 0; i < m; i++) {
      if (s[j] == t[i]) j++;
      if (j == n) return true;
    }

    return false;
  }
};