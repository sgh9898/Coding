class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int col = obstacleGrid.size(), row = obstacleGrid[0].size();
        vector<vector<int>> grid(col,vector<int>(row,0));
        int mark;

        // horizontal
        for (mark = 0; mark < col; mark++) {
            if (obstacleGrid[mark][0] == 1) {
                break;
            }
            grid[mark][0] = 1;
        }
        for (int i = mark; i < col; i++) {
            grid[i][0] = 0;
        }

        // vertical
        for (mark = 0; mark < row; mark++) {
            if (obstacleGrid[0][mark] == 1) {
                break;
            }
            grid[0][mark] = 1;
        }
        for (int j = mark; j < row; j++) {
            grid[0][j] = 0;
        }

        
        for (int i = 1; i < col; i++) {
            for (int j = 1; j < row; j++) {
                if (obstacleGrid[i][j] == 1) {
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
                }
            }
        }
        return grid[col-1][row-1];
    }
};
