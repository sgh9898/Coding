class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        // sort intervals by left ends
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int lt = intervals[0][0], rt = intervals[0][1];
        ans.push_back({lt, rt});
        for (int i = 1; i < intervals.size(); i++) {
            lt = intervals[i][0], rt = intervals[i][1];
            // merge
            if (lt <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], rt);
            // push new intervals
            } else {
                ans.push_back({lt, rt});
            }
        }
        return ans;
    }
};