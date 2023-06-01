class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int buy = 1e9, maxx = 0;
        for (int i : prices) {
            buy = min(buy, i);
            maxx = max(maxx, i - buy);
        }

        return maxx;
    }
};