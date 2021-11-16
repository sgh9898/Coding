class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row_check[9][9] = {0};
        int col_check[9][9] = {0};
        int box_check[9][9] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int num = board[i][j] - '1';
                if (row_check[i][num]++) {
                    return false;
                } else if (col_check[j][num]++) {
                    return false;
                } else if (box_check[(i/3)*3 + j/3][num]++) {
                    return false;
                }
            }
        }
        return true;
    }
};
