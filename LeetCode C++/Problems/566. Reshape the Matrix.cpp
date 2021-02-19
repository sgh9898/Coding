class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row_limit = nums[0].size(), col_limit = nums.size();
        if (r * c == row_limit * col_limit && r != col_limit) {
            vector<vector<int>> res(r, vector<int>(c));
            for (int i = 0; i < r * c; i++) {
                res[i/c][i % c] = nums[i/row_limit][i % row_limit];
            }
            return res;
        } else {
            return nums;
        }
    }
};
