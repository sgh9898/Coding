class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        if (len1 * len2 == 0)  return len1 + len2;

        int dist[len1 + 1][len2 + 1];
        // Initialization
        for (size_t i = 0; i < len1 + 1; i++) {
            dist[i][0] = i;
        }
        for (size_t j = 0; j < len2 + 1; j++) {
            dist[0][j] = j;
        }

        // dp
        for (size_t i = 1; i < len1 + 1; i++) {
            for (size_t j = 1; j < len2 + 1; j++) {
                // 3 cases: insertion in word1, insertion in word2, and replacement
                if (word1[i - 1] == word2[j - 1]) {
                    dist[i][j] = min(dist[i][j - 1] + 1, min(dist[i - 1][j] + 1, dist[i - 1][j - 1]));
                } else {
                    dist[i][j] = 1 + min(dist[i][j - 1], min(dist[i - 1][j], dist[i - 1][j - 1]));
                }
            }
        }
        return dist[len1][len2];
    }
};
