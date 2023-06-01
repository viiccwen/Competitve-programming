class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int mat_r = mat.size(), mat_c = mat[0].size();
        if (mat_r * mat_c != r * c) return mat;

        vector<vector<int>> res(r, vector<int>(c));
        int res_r = 0, res_c = 0;
        for (int i = 0; i < mat_r; i++) {
            for (int j = 0; j < mat_c; j++) {
                res[res_r][res_c++] = mat[i][j];
                if (res_c >= c) {
                    res_r++;
                    res_c = 0;
                }
            }
        }

        return res;
    }
};