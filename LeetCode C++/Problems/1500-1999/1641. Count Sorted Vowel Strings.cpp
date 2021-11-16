class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp;
        // previous turn and current turn
        dp.push_back(vector<int> (5, 1));
        dp.push_back(vector<int> (5, 0));

        int sum = 5;
        for (size_t i = 1; i < n; i++) {
            sum = 0;
            for (size_t j = 0; j < 5; j++) {
                // dp[curr_turn][alpha] = sum of dp[previous_turn][alpha ~ end]
                dp[i % 2][j] = 0;
                for (size_t t = j; t < 5; t++) {
                    dp[i % 2][j] += dp[1 - (i % 2)][t];
                }
                sum += dp[i % 2][j];
            }
        }
        return sum;
    }
};
