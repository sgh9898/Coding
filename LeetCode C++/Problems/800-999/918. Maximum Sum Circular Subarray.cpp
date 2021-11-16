class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Maximum is in the middle.
        int sum = 0, local_max = 0, max_sum = INT_MIN;
        for (int num : nums) {
            sum += num;
            local_max += num;
            max_sum = max(max_sum, local_max);
            if (local_max < 0) {
                local_max = 0;
            }
        }

        // Maximum is in the circle. Then find the minimum in the middle.
        int local_min = 0, min_sum = INT_MAX;
        for (size_t i = 1; i < nums.size() - 1; i++) {
            local_min += nums[i];
            min_sum = min(local_min, min_sum);
            if (local_min > 0) {
                local_min = 0;
            }
        }
        if (min_sum == INT_MAX) {
            return max_sum;
        } else {
            return max(sum - min_sum, max_sum);
        }
    }
};
