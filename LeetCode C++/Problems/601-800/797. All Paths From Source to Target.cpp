class Solution {
public:
    void backtrack(vector<vector<int>>& graph, int idx, vector<vector<int>>& res, vector<int>& sub_res) {
        // return if the start of a path is not 0
        if (!sub_res.empty() && sub_res[0] != 0) {
            return;
        }

        // record if a path reaches n-1
        if (idx == graph.size() - 1) {
            sub_res.push_back(idx);
            res.push_back(sub_res);
            sub_res.pop_back();
        } else {
            for (int i = 0; i < graph[idx].size(); i++) {
                sub_res.push_back(idx);
                backtrack(graph, graph[idx][i], res, sub_res);
                sub_res.pop_back();
            }
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> sub_res;
        backtrack(graph, 0, res, sub_res);
        return res;
    }
};
