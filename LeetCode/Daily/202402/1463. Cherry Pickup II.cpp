class Solution {
public:
    vector<vector<vector<int>>> dp;
    int n, m;
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        dp.assign(70, vector<vector<int>>(70, vector<int>(70, -1) ) );

        return max(0,memo(grid, 0, 0, m - 1));
    }
    int memo(vector<vector<int>>& grid, int r, int c1, int c2){
        if(c1 < 0 || c1 == m || c2 < 0 || c2 == m) return -1e9;

        if(r == n) return 0;

        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
        
        int best = 0;
        for(int i = -1; i <= 1; i++)
            for(int j = -1; j <= 1; j++)
                best = max(best, memo(grid, r + 1, c1 + i, c2 + j));

        return dp[r][c1][c2] = best + (c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2]);
    }
};