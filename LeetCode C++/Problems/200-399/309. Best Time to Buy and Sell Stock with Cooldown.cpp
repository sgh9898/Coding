class Solution {
public:
	int maxProfit(vector<int>& prices) {
    	int keep = - prices[0], sell = 0, skip = 0;
    	for (int i = 1; i < prices.size(); i++) {
    		// keep or buy
    		int new_keep = max(keep, skip - prices[i]);
    		// sell
    		int new_sell = keep + prices[i];
    		// skip
    		int new_skip = max(sell, skip);
    		tie(keep, sell, skip) = {new_keep, new_sell, new_skip};
    	}
    	return max(sell, skip);
    }

	// int maxProfit(vector<int>& prices) {
	// 	int n = prices.size();
	// 	vector<vector<int>> dp(n, vector<int>(3));
	// 	// 0: keep or buy, 1: sell, 2: skip
	// 	dp[0][0] = - prices[0];
	// 	for (int i = 1; i < prices.size(); i++) {
	// 		// keep or buy
	// 		dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
	// 		// sell
	// 		dp[i][1] = dp[i - 1][0] + prices[i];
	// 		// skip
	// 		dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
	// 	}
	// 	return max(dp[n - 1][1], dp[n - 1][2]);
	// }
};