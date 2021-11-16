class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        map<int, vector<int>> degree;
        for (int i = 0; i < nums.size(); i++) {
            if (!degree.count(nums[i])) {
                degree[nums[i]].push_back(1); // frequency
                degree[nums[i]].push_back(i); // start
                degree[nums[i]].push_back(i); // end
            } else {
                degree[nums[i]][0]++;
                degree[nums[i]][2] = i;
            }
        }
        int max_freq = 0, len = 0;
        for (auto iter = degree.begin(); iter != degree.end(); iter++) {
            if (iter->second[0] > max_freq) {
                max_freq = iter->second[0];
                len = iter->second[2] - iter->second[1] + 1;
            } else if (iter->second[0] == max_freq) {
                len = min(iter->second[2] - iter->second[1] + 1, len);
            }
        }
        return len;
    }
};
