class Solution {
 public:
  bool dfs(string s, unordered_set<string>& us,
           unordered_map<string, bool>& memo) {
    if (memo.count(s)) return memo[s];

    if (us.count(s)) return true;

    for (int i = 1; i < s.size(); i++) {
      string pre = s.substr(0, i);
      if (us.count(pre) && dfs(s.substr(i), us, memo)) return memo[s] = true;
    }

    return memo[s] = false;
  }
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> us(wordDict.begin(), wordDict.end());
    unordered_map<string, bool> memo;
    return dfs(s, us, memo);
  }
};