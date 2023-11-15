class Solution {
 public:
  int countPalindromicSubsequence(string s) {
    vector<pair<int, int>> v(26, {-1, -1});
    int n = s.size();

    for (int i = 0; i < n; i++) {
      char chr = s[i] - 'a';
      if (v[chr].first == -1)
        v[chr].first = i;
      else
        v[chr].second = i;
    }

    int ans = 0;

    for (int i = 0; i < 26; i++) {
      if (v[i].second != -1) {
        unordered_set<char> st;

        for (int k = v[i].first + 1; k < v[i].second; k++) st.insert(s[k]);

        ans += static_cast<int>(st.size());
      }
    }

    return ans;
  }
};

// aabaa