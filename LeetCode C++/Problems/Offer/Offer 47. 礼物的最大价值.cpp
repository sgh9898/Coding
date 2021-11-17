class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
    	int vert = grid.size(), horiz = grid[0].size();
    	// larger than grid to avoid edge cases
    	vector<vector<int>> dp(vert + 1, vector<int>(horiz + 1, 0));

    	for (int i = 1; i <= vert; i++) {
    		for (int j = 1; j <= horiz; j++) {
    			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
    		}
    	}
    	return dp[vert][horiz];
    }
};