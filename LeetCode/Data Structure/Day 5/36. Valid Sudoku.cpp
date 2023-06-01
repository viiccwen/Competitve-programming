class Solution {
public:
    int box_row_reg = -1, box_col_reg = -1;
    bool box_status_reg;
    bool CheckCol(vector<vector<char>>& board, int col) {
        unordered_set<char> s;
        for (int i = 0; i < 9; i++) {
            if (board[i][col] != '.') {
                if (!s.count(board[i][col]))
                    s.insert(board[i][col]);
                else
                    return false;
            }
        }
        return true;
    }

    bool CheckRow(vector<vector<char>>& board, int row) {
        unordered_set<char> s;
        for (int i = 0; i < 9; i++) {
            if (board[row][i] != '.') {
                if (!s.count(board[row][i]))
                    s.insert(board[row][i]);
                else
                    return false;
            }
        }
        return true;
    }

    bool CheckBox(vector<vector<char>>& board, int row, int col) {
        unordered_set<char> s;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int temp = board[row + i][col + j];
                if (temp != '.') {
                    if (!s.count(temp))
                        s.insert(temp);
                    else
                        return false;
                }
            }
        }
        return true;
    }

    bool CheckVid(vector<vector<char>>& board, int row, int col) {
        bool check_col, check_row, check_box;
        int box_row = row - row % 3, box_col = col - col % 3;
        check_col = CheckCol(board, col);
        check_row = CheckRow(board, row);
        check_box = CheckBox(board, box_row, box_col);

        return check_row && check_col && check_box;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!CheckVid(board, i, j)) return false;
            }
        }
        return true;
    }
};