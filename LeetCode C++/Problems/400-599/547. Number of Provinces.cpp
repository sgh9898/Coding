class Solution {
public:
    void BFS(vector<vector<int>>& isConnected, vector<bool>& visited, int provinces, int i) {
        for (size_t j = 0; j < isConnected[0].size(); j++) {
            if (!visited[j] && isConnected[i][j] == 1) {
                visited[j] = true;
                BFS(isConnected, visited, provinces, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int provinces = 0;
        for (size_t i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                BFS(isConnected, visited, provinces, i);
                provinces++;
            }
        }
        return provinces;
    }
};
