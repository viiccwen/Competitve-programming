class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // const int MOD = 1e9 + 7;
        // vector<vector<int>> dir = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
        // stack<pair<int, int>> stk;
        // int path = 0;

        // stk.push({startRow, startColumn});
        // for(int i=0; i<maxMove; ++i) {
        //     if(stk.empty()) break;
        //     else {
        //         int size = stk.size();
        //         cout << size << '\n';
        //         for(; size>0; --size) {
        //             int x = stk.top().first;
        //             int y = stk.top().second;
        //             stk.pop();

        //             for(int j=0; j<4; ++j) {
        //                 int nx = x + dir[j][0];
        //                 int ny = y + dir[j][1];
                        
        //                 if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
        //                     stk.push({nx, ny});
        //                 } else path++;
        //             }
        //         }
                
        //     }
        //     path %= MOD;
        // }

        // return path;
        const int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Initialization for 1 move
        for (int move = 1; move <= maxMove; move++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for (auto& dir : directions) {
                        int ni = i + dir.first, nj = j + dir.second;
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
                            dp[move][i][j]++;
                        } else {
                            dp[move][i][j] = (dp[move][i][j] + dp[move - 1][ni][nj]) % MOD;
                        }
                    }
                }
            }
        }
        return dp[maxMove][startRow][startColumn];
    }
};