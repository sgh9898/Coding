class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, sum_total = INT_MIN;
        for (int num : nums) {
            sum += num;
            sum_total = max(sum, sum_total);
            if (sum < 0) sum = 0;
        }
        return sum_total;
    }
};