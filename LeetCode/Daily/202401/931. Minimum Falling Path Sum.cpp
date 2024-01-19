class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> dir = {-1, 0, 1};

        for(int i=0;i<n;i++) dp[0][i] = mat[0][i];
        

        for(int i1=1; i1<n; ++i1) {
            for(int i2=0; i2<n; ++i2) {
                int min_prev = INT_MAX;
                for(int i3=0; i3<3; ++i3) {
                    if(i2 == 0 && i3 == 0) continue;
                    if(i2 == n-1 && i3 == 2) continue;
                    min_prev = min(min_prev, dp[i1 - 1][i2 + dir[i3]]);
                }

                dp[i1][i2] = mat[i1][i2] + min_prev;
            }
        }

        int minn = INT_MAX;
        for(int i=0; i<n; ++i) 
            minn = min(minn, dp[n-1][i]);
        
        return minn;
    }
};