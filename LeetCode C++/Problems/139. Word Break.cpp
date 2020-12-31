class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        vector<int> dp(size + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < size; i++) {
            if (dp[i] == 0)
                continue;
            for (auto &str : wordDict) {
                int len = str.size();
                if (i + len < size + 1 && s.substr(i, len) == str) {
                    dp[i+len] = 1;
                }
            }
        }
        return dp[size];
    }
};
