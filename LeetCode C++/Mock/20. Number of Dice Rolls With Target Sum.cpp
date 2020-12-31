class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        const int MOD = 1e9+7;
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));  // dp[num of dice][target]
        dp[0][0] = 1;  // base case
        //
        for (int i = 1; i <= d; i++) {  // number of dices
            for (int j = 1; j <= target; j++) {  // target
                for (size_t k = 1; k <= f; k++) {
                    if (j >= k) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
                    }
                }
            }
        }
        return dp[d][target];
    }
};
