double dp[2][25][25], les = 1e-7;
int dir[8][2] = {{2, 1}, {-2, 1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, -1}, {-2, -1}};
class Solution {
public:
    double knightProbability(int n, int k, int r, int c) {
        int idx = 0;
        double ans = 0;
        memset(dp, 0, sizeof(dp));
        dp[idx][r][c] = 1;
        while (k--){
            memset(dp[!idx], 0, sizeof(dp[!idx]));
            for (int x = 0; x < n; ++x)
            for (int y = 0; y < n; ++y){
                if (dp[idx][x][y] > les){
                    for (int i = 0; i < 8; ++i){
                        int nx = x + dir[i][0], ny = y + dir[i][1];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            ans += dp[idx][x][y] * 0.125;
                        else
                            dp[!idx][nx][ny] += dp[idx][x][y] / 8;
                    }
                }
            }
            idx ^= 1; 
        }
        return 1 - ans;
    }
};