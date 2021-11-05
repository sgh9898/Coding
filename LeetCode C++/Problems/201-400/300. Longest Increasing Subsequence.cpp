class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())   return 0;
        int n = nums.size();
        vector<int> tail;
        for (size_t i = 0; i < n; i++) {
            auto iter = lower_bound(tail.begin(), tail.end(), nums[i]);
            if (iter == tail.end()) {
                tail.push_back(nums[i]);
            } else {
                *iter = nums[i];
            }
        }
        return tail.size();
    }
};
