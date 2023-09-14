class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int r = grid.size(), c = grid[0].size();
    vector<vector<int>> dp(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++) {
      if (!grid[i][0])
        dp[i][0] = 1;
      else
        break;
    }
    for (int i = 0; i < c; i++) {
      if (!grid[0][i])
        dp[0][i] = 1;
      else
        break;
    }

    for (int i = 1; i < r; i++) {
      for (int j = 1; j < c; j++) {
        if (!grid[i][j]) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[r - 1][c - 1];
  }
};