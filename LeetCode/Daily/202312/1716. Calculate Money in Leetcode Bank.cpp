class Solution {
 public:
  int totalMoney(int n) {
    int a = n / 7;
    int b = n % 7;
    int total = a * 28 + 7 * (a - 1) * a / 2 + (b * (1 + b) / 2 + a * b);
    return total;
  }
};

/*
a = n / 7
b = n % 7
a * 28 + 7 * (a - 1) * a / 2 + (b * (1 + b) / 2 + a * b)
1 2 3 4 5 6 7 = 28
2 3 4 5 6 7 8 = 35 = 28 + 7 * 1
3 4 5 6 7 8 9 = 42 = 28 + 7 * 2
*/