class Solution {
public:
    bool isPerfectSqueare(int& n, int& target) {
        return n*n == target;
    }
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        int perfectN = 1;
        dp[0] = 0;
        
        while(perfectN * perfectN <= n) {
            int ps = perfectN * perfectN;
            for(int i=ps; i<n+1; ++i) 
                dp[i] = min(dp[i - ps] + 1, dp[i]);
            
            perfectN++;
        }

        return dp[n];
    }
};
// ^     ^         ^                   ^        
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// 1 2 3 1 2 3 4 2 1 2  3  3  2  3  3  1  2  2