class Solution {
 public:
  int minimumOneBitOperations(int n) {
    bitset<32> bit(n);
    string str = bit.to_string();
    int ans = 0, k = str.size();
    bool flag = true;

    for (int i = 0; i < k; i++) {
      if (str[i] == '1') {
        ans += flag ? pow(2, k - i) - 1 : -(pow(2, k - i) - 1);
        flag = !flag;
      }
    }

    return ans;
  }
};

/*
110
010 -> 3 -> 2^2 - 1
100 -> 7 -> 2^3 - 1
7 - 3
*/