class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> min_path(triangle.back());
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                min_path[j] = min(min_path[j+1], min_path[j]) + triangle[i][j];
            }
        }
        return min_path[0];
    }
};
