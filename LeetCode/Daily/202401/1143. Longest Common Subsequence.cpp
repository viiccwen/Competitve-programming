class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for(int i1=1; i1<=n1; ++i1) {
            for(int i2=1; i2<=n2; ++i2) {
                if(text1[i1-1] == text2[i2-1]) dp[i1][i2] = dp[i1-1][i2-1] + 1;
                else dp[i1][i2] = max(dp[i1-1][i2], max(dp[i1][i2-1], dp[i1-1][i2-1]));
            }
        }

        return dp[n1][n2];
    }
};

/*
    a c e
  0 0 0 0
a 0 1 1 1 
b 0 1 1 1
c 0 1 2 2
d 0 1 2 2
e 0 1 2 3
*/