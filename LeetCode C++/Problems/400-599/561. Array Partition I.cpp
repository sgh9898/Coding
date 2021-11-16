class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<>());
        int sum = 0;
        for (int i = 1; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};
