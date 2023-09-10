class Solution {
 private:
  unordered_set<string> us;
  unordered_map<int, int> memo;
  int len;
  string k;

 public:
  int dp(int start) {
    if (start == len) return 0;
    if (memo.count(start)) return memo[start];

    int ans = dp(start + 1) + 1;
    for (int end = start; end < len; end++) {
      auto cur = k.substr(start, end - start + 1);
      if (us.count(cur)) ans = min(ans, dp(end + 1));
    }

    return memo[start] = ans;
  }
  int minExtraChar(string s, vector<string>& dictionary) {
    for (auto ite : dictionary) us.insert(ite);

    k = s;
    len = s.size();

    return dp(0);
  }
};