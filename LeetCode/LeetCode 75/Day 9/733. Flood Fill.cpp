class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;

        int r = image.size(), c = image[0].size();
        int pre_clr = image[sr][sc];
        int now_sr, now_sc, next_sr, next_sc;
        vector<pair<int, int>> dir = { {-1,0},{1,0},{0,-1},{0,1} };

        queue<pair<int, int>> q;
        q.push({ sr, sc });
        while (!q.empty()) {
            now_sr = q.front().first, now_sc = q.front().second;
            image[now_sr][now_sc] = color;
            q.pop();

            for (int i = 0; i < 4; i++) {
                next_sr = now_sr + dir[i].first, next_sc = now_sc + dir[i].second;
                if (next_sr >= 0 && next_sr < r && next_sc >= 0 && next_sc < c && image[next_sr][next_sc] == pre_clr)
                    q.push({ next_sr, next_sc });
            }
        }

        return image;
    }
};