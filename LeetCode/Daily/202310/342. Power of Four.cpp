class Solution {
 public:
  bool isPowerOfFour(int n) {
    if (n <= 0) return false;
    if (n == 1) return true;

    while (n > 1) {
      if (n % 4 == 0)
        n /= 4;
      else
        return false;
    }

    return true;
  }
};