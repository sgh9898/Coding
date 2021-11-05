class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int limit = nums.size();
        vector<int> dp(limit, 0);

        // initilization
        for (int i = 0; i < limit; i++) {
            dp[i] = nums[i];
        }

        // how much more stones can player 1 get
        for (int i = limit - 2; i >= 0; i--) {
            for (int j = i + 1; j < limit; j++) {
                // dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }

        return dp[limit - 1] > 0;
    }
};
