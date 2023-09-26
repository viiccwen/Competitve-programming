class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    vector<int> cur(text2.size() + 1, 0);
    vector<int> next(text2.size() + 1, 0);

    for (int i = text1.size() - 1; i >= 0; i--) {
      for (int j = text2.size() - 1; j >= 0; j--) {
        int ans;
        if (text1[i] == text2[j])
          ans = 1 + next[j + 1];
        else
          ans = max(cur[j + 1], next[j]);

        cur[j] = ans;
      }
      next = cur;
    }

    return next[0];
  }
};