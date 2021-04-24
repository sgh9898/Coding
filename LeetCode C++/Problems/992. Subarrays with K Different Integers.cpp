class Solution {
public:
    void Backtracking(vector<vector<int>>& res, vector<int>& curr, vector<int>& source, int idx, int K) {
        set<int> temp(curr.begin(), curr.end());
        if (temp.size() == K) {
            res.push_back(curr);
            for (int i = 0; i < curr.size(); i++) {
                cout<<curr[i]<<" ";
            }
            cout<<endl;
        }
        for (int i = idx; i < source.size(); i++) {
            curr.push_back(source[i]);
            Backtracking(res, curr, source, i + 1, K);
            curr.pop_back();
        }
    }

    int subarraysWithKDistinct(vector<int>& A, int K) {
        vector<vector<int>> res;
        vector<int> curr;
        Backtracking(res, curr, A, 0, K);
        return res.size();
    }
};
