class Solution {
 public:
  int minDeletions(string s) {
    unordered_map<char, int> mp;
    int res = 0;

    for (auto c : s) mp[c]++;

    unordered_set<int> st;
    for (auto ite : mp) {
      int freq = ite.second;
      while (1) {
        if (st.count(freq)) {
          res++;
          freq--;
        } else if (!freq)
          break;
        else if (!st.count(freq)) {
          st.insert(freq);
          break;
        }
      }
    }

    return res;
  }
};