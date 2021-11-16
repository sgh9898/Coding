class Solution {
public:
    // Top-right/bottom-left is the midpoint of top-left/bottom-right.
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size() - 1;
        int i_limit = matrix.size();
        while (i < i_limit && j >= 0) {
            int curr = matrix[i][j];
            if (curr == target) {
                return true;
            } else if (curr < target){
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};