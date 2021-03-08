class NumMatrix {
private:
    vector<vector<int>> prefix_sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (!matrix.empty()) {
            int max_row = matrix.size(), max_col = matrix[0].size();
            prefix_sum = vector<vector<int>> (max_row + 1, vector<int> (max_col + 1, 0));
            for (int i = 1; i <= max_row; i++) {
                for (int j = 1; j <= max_col; j++) {
                    prefix_sum[i][j] = matrix[i - 1][j - 1] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (prefix_sum.empty()) {
            return 0;
        } else {
            return prefix_sum[row2 + 1][col2 + 1] - prefix_sum[row2 + 1][col1] - prefix_sum[row1][col2 + 1] + prefix_sum[row1][col1];
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
