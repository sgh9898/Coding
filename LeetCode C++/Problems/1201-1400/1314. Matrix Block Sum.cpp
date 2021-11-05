class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int row_limit = mat.size(), col_limit = mat[0].size();
        vector<vector<int>> prefix_sum(row_limit + 1, (vector<int>(col_limit + 1, 0)));
        vector<vector<int>> block_sum(row_limit, (vector<int>(col_limit, 0)));

        // calculating prefix sum, handling edge cases
        for (int i = 1; i <= row_limit; i++) {
            for (int j = 1; j <= col_limit; j++) {
                prefix_sum[i][j] = mat[i - 1][j - 1] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
            }
        }

        // calculating block sum
        for (int i = 1; i <= row_limit; i++) {
            for (int j = 1; j <= col_limit; j++) {
                // block_sum = prefix_sum[bot] - (2 * rectangles - overlapping)
                int i_top = max(i - K - 1, 0), i_bot = min(i + K, row_limit);
                int j_top = max(j - K - 1, 0), j_bot = min(j + K, col_limit);
                block_sum[i - 1][j - 1] = prefix_sum[i_bot][j_bot] - prefix_sum[i_top][j_bot] - prefix_sum[i_bot][j_top] + prefix_sum[i_top][j_top];
            }
        }
        return block_sum;
    }
};
