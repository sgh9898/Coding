class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](const vector<int>& lt, const vector<int>& rt) {
            return lt[1] <= rt[1];
        });
        int pos = points[0][1];
        int arrow = 1;
        for (const vector<int>& temp : points) {
            if (temp[0] > pos) {
                arrow++;
                pos = temp[1];
            }
        }
        return arrow;
    }
};
