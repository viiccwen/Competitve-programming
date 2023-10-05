class Solution {
 public:
  static bool cmp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
  int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), cmp);

    int prev = 0, cnt = 1;
    for (int i = 1; i < pairs.size(); i++) {
      if (pairs[prev][1] < pairs[i][0]) {
        prev = i;
        cnt++;
      }
    }

    return cnt;
  }
};