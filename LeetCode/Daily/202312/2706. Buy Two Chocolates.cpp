class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int debt = money - prices[1] - prices[0];
        return (debt >= 0) ? debt : money;
    }
};