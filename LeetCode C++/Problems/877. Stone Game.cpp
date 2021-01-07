class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int limit = piles.size();
        vector<int> dp(limit, 0);

        // initilization
        for (int i = 0; i < limit; i++) {
            dp[i] = piles[i];
        }

        // how much more stones can player 1 get
        for (int i = limit - 2; i >= 0; i--) {
            for (int j = i + 1; j < limit; j++) {
                // dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
            }
        }

        return dp[limit - 1] > 0;
    }
};
