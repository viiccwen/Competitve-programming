class Solution {
 public:
  int candy(vector<int>& ratings) {
    int len = ratings.size();
    vector<int> greedy(len, 1);

    for (int i = 1; i < len; i++) {
      if (ratings[i] > ratings[i - 1]) greedy[i] = greedy[i - 1] + 1;
    }

    for (int i = len - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1])
        greedy[i] = max(greedy[i], greedy[i + 1] + 1);
    }

    int amount = 0;
    for (auto num : greedy) amount += num;

    return amount;
  }
};