class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())   return 0;
        int limit = nums.size();
        if (limit == 1) return nums[0];
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < limit; i++) {
            int temp = second;
            second = max(second, first + nums[i]);
            first = temp;
        }
        return second;
    }
};
