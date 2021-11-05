class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX-3);
        for(int i = 1; i*i <= n; i++) dp[i*i] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j*j <= i; j++){
                dp[i] =min(dp[i], dp[i-j*j] + 1);
            }
        }
        return dp[n]；
    }
};
