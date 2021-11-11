class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int col_limit = matrix.size(), row_limit = matrix[0].size();
        vector<int> dp(row_limit);

        // first row
        for (int j = 0; j < row_limit; j++) {
            dp[j] = matrix[0][j];
        }
        string x = 
        // dp
        for (int i = 1; i < col_limit; i++) {
            // first element in a row
            int left_top = dp[0];
            dp[0] = min(dp[0], dp[1]) + matrix[i][0];

            for (int j = 1; j < row_limit; j++) {
                // edge cases
                int rt = min(row_limit - 1, j + 1);
                int temp = dp[j];
                dp[j] = min(min(left_top, dp[j]), dp[rt]) + matrix[i][j];
                left_top = temp;
            }
        }
        // find the minimum
        int min_path = INT_MAX;
        for (int i = 0; i < row_limit; i++) {
            min_path = min(min_path, dp[i]);
        }
        return min_path;
    }
};