class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], local_max = nums[0], local_min = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            // positive
            if (nums[i] >= 0) {
                local_max = max(nums[i], local_max * nums[i]);
                local_min = min(nums[i], local_min * nums[i]);
            } else {    // negative
                int temp = local_max;
                local_max = max(nums[i], local_min * nums[i]);
                local_min = min(nums[i], temp * nums[i]);
            }
            ans = max(ans, local_max);
        }
        return ans;
    }
};
