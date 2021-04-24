class Solution {
public:
    void backtracking(vector<int>& src, int idx, vector<vector<int>>& res, vector<int>& sub_res) {
        // if statement here to cut branches
        res.push_back(sub_res);  // record
        for (int i = idx; i < src.size(); i++) {
            sub_res.push_back(src[i]);  // choose
            backtracking(src, idx, res, sub_res);  // choose from the rest
            sub_res.pop_back(); // remove extra elements
        }
    }
};
