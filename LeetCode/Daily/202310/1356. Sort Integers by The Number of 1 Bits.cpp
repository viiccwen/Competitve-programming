class Solution {
 public:
  static bool cmp(int &a, int &b) {
    bitset<32> bitA(a);
    bitset<32> bitB(b);

    if (bitA.count() == bitB.count()) return a < b;
    return bitA.count() < bitB.count();
  }
  vector<int> sortByBits(vector<int> &arr) {
    sort(arr.begin(), arr.end(), cmp);

    return arr;
  }
};