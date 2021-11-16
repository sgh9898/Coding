class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int best = INT_MIN, lt = values[0] + 0;
        for (int j = 1; j < values.size(); j++) {
            // updating scores
            best = max(best, lt + values[j] - j);
            // left point
            lt = max(lt, values[j] + j);
        }
        return best;
    }
};