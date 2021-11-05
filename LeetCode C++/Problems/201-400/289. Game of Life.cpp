class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ans(board);
        int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
        int dy[8] = {1, -1, 0, 1, -1, 1, -1, 0};
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                int cnt = 0;
                for(int z = 0; z < 8; z++){
                    int x = i + dx[z];
                    int y = j + dy[z];
                    if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == 1)
                        cnt ++;
                }
                if(cnt < 2) ans[i][j] = 0;
                else if(cnt > 3)    ans[i][j] = 0;
                else if(cnt == 3)   ans[i][j] = 1;
            }
        }
        board = ans;
        return;
    }
};
