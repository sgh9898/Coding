class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            long int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum >= lower && sum <= upper) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
