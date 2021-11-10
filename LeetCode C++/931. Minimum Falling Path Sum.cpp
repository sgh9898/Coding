class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
    	int col_limit = matrix.size(), row_limit = matrix[0].size();
    	vector<vector<int>> dp(col_limit, vector<int>(row_limit));
    	// first row
    	for (int i = 0; i < row_limit; i++) {
    		dp[0][i] = matrix[0][i];
    	}
    	for (int i = 1; i < col_limit; i++) {
    		for (int j = 0; j < row_limit; j++) {
    			// edge cases
    			int lt = max(0, j - 1), rt = min(row_limit - 1, j + 1);
    			dp[i][j] = min(min(dp[i - 1][lt], dp[i - 1][j]), dp[i - 1][rt]) + matrix[i][j];
    		}
    	}
    	int min_path = INT_MAX;
    	for (int i = 0; i < row_limit; i++) {
    		min_path = min(min_path, dp[col_limit - 1][i]);
    	}
    	return min_path;
    }
};