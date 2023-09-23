class Solution {
 public:
  vector<int> dp;
  int max_chain = 1;
  bool static cmp(string a, string b) { return a.size() < b.size(); }
  bool check(vector<string>& words, string& a, string& b) {
    int len1 = a.size(), len2 = b.size();
    int k = 0;
    bool dif = false;
    for (int i = 0; i < len2; i++) {
      if (b[i] == a[k])
        k++;
      else {
        if (!dif)
          dif = true;
        else
          return false;
      }
    }

    return dif;
  }
  int longestStrChain(vector<string>& words) {
    if (words.size() == 1) return 1;

    int n = words.size();
    dp.assign(n, 1);
    sort(words.begin(), words.end(), cmp);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (words[j].size() - words[i].size() == 0) continue;
        if (words[j].size() - words[i].size() > 1) break;
        if (check(words, words[i], words[j])) dp[j] = max(dp[j], dp[i] + 1);
      }
      max_chain = max(max_chain, dp[i]);
    }

    return max_chain;
  }
};