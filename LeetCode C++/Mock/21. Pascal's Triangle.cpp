class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        if (numRows < 1) return triangle;
        triangle.push_back({1});
        for (int i = 1; i < numRows; i++) {
            vector<int> temp(i + 1, 0);
            temp[0] = 1;
            temp[i] = 1;
            for (int j = 1; j < i; j++) {
                temp[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(temp);
        }
        return triangle;
    }
};
