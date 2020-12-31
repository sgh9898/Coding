class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted = heights;
        sort(sorted.begin(), sorted.end());
        int cnt = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            if (heights[i] != sorted[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};
