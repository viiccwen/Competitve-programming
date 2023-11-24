class Solution {
 public:
  int maxCoins(vector<int>& piles) {
    sort(piles.begin(), piles.end());
    int left = 0, right = piles.size() - 1;
    int maxx = 0;
    for (int i = right - 1; i > left; i -= 2) {
      maxx += piles[i];
      left++;
    }

    return maxx;
  }
};