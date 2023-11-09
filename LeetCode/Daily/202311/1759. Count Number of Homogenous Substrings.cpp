class Solution {
 public:
  int countHomogenous(string s) {
    long long res = 0;
    int start = 0;
    int MOD = 1e9 + 7;
    int n = s.size();

    for (int i = 0; i < n; i++) {
      if (s[i] != s[start]) {
        int appear = i - start;
        while (appear > 0) {
          res += appear;
          appear--;
        }
        start = i;
      }
    }

    int appear = n - start;
    while (appear > 0) {
      res += appear;
      appear--;
    }

    return static_cast<int>(res % (MOD));
  }
};