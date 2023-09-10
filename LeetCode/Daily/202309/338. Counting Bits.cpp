class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> cnt(n + 1);
    bitset<20> b;

    for (int i = 0; i <= n; i++) {
      b = i;
      cnt[i] = b.count();
    }

    return cnt;
  }
};