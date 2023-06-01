class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int now_r, now_c, next_r, next_c;
        int ans = 0;
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = { {-1,0},{1,0},{0,-1},{0,1} };

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = 'x';
                    q.push({ i,j });
                    ans++;
                    while (!q.empty()) {
                        now_r = q.front().first, now_c = q.front().second;
                        q.pop();
                        for (int i = 0; i < 4; i++) {
                            next_r = now_r + dir[i].first, next_c = now_c + dir[i].second;
                            if (next_r >= 0 && next_r < r && next_c >= 0 && next_c < c && grid[next_r][next_c] == '1') {
                                grid[next_r][next_c] = 'x';
                                q.push({ next_r, next_c });
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};