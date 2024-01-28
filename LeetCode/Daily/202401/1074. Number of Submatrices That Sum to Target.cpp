class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();

        for(int r=0; r<m; ++r) 
            for(int c=1; c<n; ++c) mat[r][c] += mat[r][c - 1];

        int cnt = 0;

        for(int c1=0; c1<n; ++c1) {
            for(int c2=c1; c2<n; ++c2) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int sum = 0;

                for(int r=0; r<m; ++r) {
                    sum += mat[r][c2] - (c1 > 0 ? mat[r][c1 - 1] : 0);
                    cnt += mp[sum - target];
                    mp[sum]++;
                }
            }
        }

        return cnt; 
    }
};