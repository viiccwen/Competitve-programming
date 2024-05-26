class Solution {
public:
    int checkRecord(int n) {
        // n, absent, continual late day 
        int dp[100001][2][3] = { 0 };
        const long long int MOD = 1e9 + 7;
        
        for(int j=0; j<2;++j) {
            for(int k=0; k<3;++k) {
                dp[0][j][k] = 1;
            }   
        }

        for(int i=1; i<=n; ++i) {
            for(int j=0; j<2; ++j) { // absent
                for(int k=0; k<3; ++k) { // continual late
                    long long int amount = dp[i - 1][j][0]; // P
                    amount += (k < 2 ? dp[i - 1][j][k + 1] : 0); // L 
                    amount += (!j ? dp[i - 1][j + 1][0] : 0); // A
                    dp[i][j][k] = amount % MOD;
                }
            }
        }
        return dp[n][0][0];
    }
};