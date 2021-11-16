class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int rm = 0, rt = INT_MIN;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] < rt) {
                rm++;
            } else {
                rt = intervals[i][1];
            }
        }
        return rm;
    }

    // sort rightend in ascending order
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }

    // int eraseOverlapIntervals(vector<vector<int>>& intervals) {    
    //     sort(intervals.begin(), intervals.end());
    //     int rm = 0, rt = intervals[0][1];
    //     for (int i = 1; i < intervals.size(); i++) {
    //         // overlapping
    //         if (intervals[i][0] < rt) {
    //             rm++;
    //             // delete the rightside interval
    //             rt = min(rt, intervals[i][1]);
    //         } else {
    //         // non-overlapping
    //             rt = intervals[i][1];
    //         }
    //     }
    //     return rm;
    // }
};