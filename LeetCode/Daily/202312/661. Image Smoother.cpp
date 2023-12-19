class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        pair<int, int> dir[] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,0}, {0,1}, {1,-1}, {1,0}, {1,1}};

        int n = img.size(), m = img[0].size();
        vector<vector<int>> res(n, vector<int>(m));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                double sum = 0;
                int cnt = 0;

                for(int k=0; k<9; k++) {
                    int nx = i + dir[k].first, ny = j + dir[k].second;
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        cnt++;
                        sum += img[nx][ny];
                    }
                }

                res[i][j] = floor(sum / cnt);
            }
        }

        return res;
    }
};