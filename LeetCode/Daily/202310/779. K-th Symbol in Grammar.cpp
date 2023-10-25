class Solution {
 public:
  int kthGrammar(int n, int k) {
    if (n == 1) return 0;

    bool zero = true;
    n = pow(2, n - 1);

    while (n != 1) {
      n /= 2;
      if (k > n) {
        k -= n;
        zero = !zero;
      }
    }

    return zero ? 0 : 1;
  }
};