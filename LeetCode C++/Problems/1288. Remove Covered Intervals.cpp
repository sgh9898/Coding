class Solution {
public:
    static bool cmp(const vector<int>& lt, const vector<int>& rt) {
        return lt[0] < rt[0] || (lt[0] == rt[0] && lt[1] >= rt[1]);
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int rt = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][1] <= rt) {
                ans--;
            } else {
                rt = max(rt, intervals[i][1]);
            }
        }
        return ans;
    }
};
