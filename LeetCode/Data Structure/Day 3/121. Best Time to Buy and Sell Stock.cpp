class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn = prices[0], maxx = prices[0];
        int ans = 0;
        int len = prices.size();

        for (int i = 1; i < len; i++) {
            if (prices[i] > maxx) {
                maxx = prices[i];
                ans = max(ans, maxx - minn);
            }
            else if (prices[i] < minn) {
                maxx = prices[i];
                minn = prices[i];
            }
        }

        return ans;
    }
};