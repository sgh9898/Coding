class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
      // edge cases
      if (s1 == "") {
        return s2 == s3;
      }
      if (s2 == "") {
        return s1 == s3;
      }

      int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
      if (size1 + size2 != size3) {
        return false;
      }
      // dp[i][j] means s1[0, i] + s2[0, j] = s3[0, i + j]
      vector<vector<bool>> dp(size1 + 1, vector<bool>(size2 + 1, false));
      dp[0][0] = true;

      for (int i = 0; i <= size1; i++) {
        for (int j = 0; j <= size2; j++) {
          if (i > 0) {
            dp[i][j] = dp[i][j] || (dp[i - 1][j] && (s1[i - 1] == s3[i - 1 + j]));
          }
          if (j > 0) {
            dp[i][j] = dp[i][j] || (dp[i][j - 1] && (s2[j - 1] == s3[j - 1 + i]));
          }
        }
      }
      return dp[size1][size2];
    }
};
