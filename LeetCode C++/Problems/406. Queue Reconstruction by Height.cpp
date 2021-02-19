class Solution {
public:
    static bool cmp(const vector<int>& lt, const vector<int>& rt) {
        return lt[0] > rt[0] || (lt[0] == rt[0] && lt[1] < rt[1]);
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        for (const auto& person : people) {
            res.insert(res.begin() + person[1], person);
        }
        return res;
    }
};
