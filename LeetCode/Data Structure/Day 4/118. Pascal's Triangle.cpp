class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j <= i; j++) {
                if (!j || j == i)
                    pascal[i].push_back(1);
                else
                    pascal[i].push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
            }
        }

        return pascal;
    }
};