class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int sold = 0, rest = 0, hold = INT_MIN;
    for (auto price : prices) {
      int preSold = sold;
      sold = hold + price;
      hold = max(hold, rest - price);
      rest = max(rest, preSold);
    }

    return max(sold, rest);
  }
};