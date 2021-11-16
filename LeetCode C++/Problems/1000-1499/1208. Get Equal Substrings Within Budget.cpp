class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> costs;
        for (int i = 0; i < s.length(); i++) {
            costs.push_back(abs(s[i] - t[i]));
        }
        int max_length = 0, curr_cost = 0, start = 0, end = 0;
        while (end < costs.size()) {
            curr_cost += costs[end];
            while (curr_cost > maxCost) {
                curr_cost -= costs[start];
                start++;
            }
            max_length = max(max_length, end - start + 1);
            end++;
        }
        return max_length;
    }
};
