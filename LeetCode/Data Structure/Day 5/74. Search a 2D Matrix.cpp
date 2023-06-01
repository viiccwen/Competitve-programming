class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int tar_row = -1;

        // find which row is the target range
        for (int i = 0; i < row; i++) {
            if (target >= matrix[i][0] && target <= matrix[i][col - 1]) {
                tar_row = i;
                break;
            }
        }

        if (tar_row == -1) return false;

        // binarysearch
        int left = 0, right = col - 1, middle, cur;
        while (left <= right) {
            middle = left + (right - left) / 2;
            cur = matrix[tar_row][middle];

            if (target > cur) {
                left = middle + 1;
            }
            else if (target < cur) {
                right = middle - 1;
            }
            else return true;
        }
        return false;
    }
};