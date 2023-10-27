class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtracking(board, word, visited, i, j, 0) == true) {
                    return true;
                }
            }
        }

        return false;
    }

    bool backtracking(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int i, int j, int k) {
        // end
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) {
            return false;
        }
        if (k == word.size() - 1) {
            return true;
        }
        visited[i][j] = '\0';
        bool res = backtracking(board, word, visited, k + 1, i + 1, j) ||
                backtracking(board, word, visited, k + 1, i, j + 1) ||
                backtracking(board, word, visited, k + 1, i - 1, j) ||
                backtracking(board, word, visited, k + 1, i, j - 1);
        visited[i][j] = word[k];

        return res;
    }
};