class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, max_sum = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            // only need to record the sum of the extending subarray
            sum = nums[i] + sum;
            max_sum = max(max_sum, sum);
            sum = (sum < 0) ? 0 : sum;
        }
        return max_sum;
    }

    // int maxSubArray(vector<int>& nums) {
    //     int curr = nums[0], max_sum = nums[0];
    //     for (int i = 1; i < nums.size(); i++) {
    //         // only need to record the sum of the extending subarray
    //         curr = max(nums[i], nums[i] + curr);
    //         max_sum = max(max_sum, curr);
    //     }
    //     return max_sum;
    // }

    // int maxSubArray(vector<int>& nums) {
    //     vector<int> dp(nums.size());
    //     dp[0] = nums[0];
    //     int max_sum = nums[0];
    //     for (int i = 1; i < nums.size(); i++) {
    //         // extend an existing subarray or start a new one
    //         dp[i] = max(nums[i] + dp[i - 1], nums[i]);
    //         // record local max
    //         max_sum = max(max_sum, dp[i]);
    //         cout<<dp[i]<<endl;
    //     }
    //     return max_sum;
    // }
};
