class Solution {
 public:
  int integerBreak(int n) {
    if (n < 4) return n - 1;

    int x = n / 3;
    if (n % 3 == 0)
      return pow(3, x);
    else if ((n - 1) % 3 == 0)
      return pow(3, x - 1) * 4;
    else
      return pow(3, x) * 2;
  }
};
/*
2 = 1 + 1
3 = 1 + 2
4 = 2 + 2
5 = 3 + 2
6 = 3 + 3
7 = 3 + 2 + 2
8 = 3 + 3 + 2
9 = 3 + 3 + 3
10 = 3 + 3 + 2 + 2
*/

// 2 3 4 5 6 7  8  9  10
// 1 2 4 6 9 12 18 27 36