class Solution {
 public:
  int isGood(string& str, unordered_map<char, int> s) {
    for (auto c : str) {
      if (s[c] <= 0)
        return 0;
      else
        s[c]--;
    }

    return str.size();
  }
  int countCharacters(vector<string>& words, string chars) {
    unordered_map<char, int> s;
    int ans = 0;

    for (auto c : chars) s[c]++;

    for (auto str : words) {
      ans += isGood(str, s);
    }

    return ans;
  }
};