class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // initialization
        vector<vector<int>> triangle;
        for (int row = 1;row <= numRows;row++) {
            triangle.push_back(vector<int> (row,1));
        }

        // calculation
        for (int cur_row = 2;cur_row < numRows;cur_row++) {
            for (int i = 1;i < cur_row;i++) {
                triangle[row][i] = triangle[row-1][i-1] + triangle[row-1][i];
            }
        }

        return triangle;
    }
};
