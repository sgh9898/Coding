class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
        return -1;
    }

    // int findRepeatNumber(vector<int>& nums) {
    //     unordered_set<int> set;
    //     for (int num : nums) {
    //         if (!set.count(num)) {
    //             set.insert(num);
    //         } else {
    //             return num;
    //         }
    //     }
    //     return -1;
    // }
};
