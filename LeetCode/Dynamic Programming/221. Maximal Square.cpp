class Solution {
 public:
  int maximalSquare(vector<vector<char>>& mat) {
    int r = mat.size();
    int c = mat[0].size();
    int maximum = 0;
    vector<vector<int>> dp(r + 1, vector<int>(c + 1, 0));

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (mat[i][j] == '1') {
          dp[i + 1][j + 1] = min({dp[i][j], dp[i + 1][j], dp[i][j + 1]}) + 1;
          maximum = max(maximum, dp[i + 1][j + 1]);
        }
      }
    }

    return maximum * maximum;
  }
};

/*

TLE

class Solution {
public:
    vector<pair<int, int>> DIR = {{0, 1}, {1, 1}, {1, 0}};
    int maximum = 0;
    int m, n;

    void BFS(vector<vector<char>>& mat, int i, int j) {
        queue<vector<int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.push({i, j, 1});
        visited[i][j] = true;
        while(!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            int stage = q.front()[2];
            maximum = max(maximum, stage);
            q.pop();

            for(int i=0;i<3;i++) {
                int nx = x + DIR[i].first;
                int ny = y + DIR[i].second;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && mat[nx][ny] == '1')
{ if(!visited[nx][ny]) { visited[nx][ny] = true; q.push({nx, ny, stage + 1});
                    }
                    else continue;
                } else return;
            }
        }
    }
    int maximalSquare(vector<vector<char>>& mat) {
        m = mat.size();
        n = mat[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j] == '1') BFS(mat, i, j);
            }
        }

        return maximum * maximum;
    }
};
*/