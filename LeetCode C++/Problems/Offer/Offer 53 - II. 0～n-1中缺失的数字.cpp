class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int lt = 0, rt = nums.size() - 1;
        int target = nums.size();
        while (lt <= rt) {
            int mid = lt + (rt - lt) / 2;
            if (nums[mid] != mid) {
                target = mid;
                rt = mid - 1;
            } else {
                lt = mid + 1; 
            }
        }
        return target;
    }

    // int missingNumber(vector<int>& nums) {
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (i != nums[i]) {
    //             return i;
    //         }
    //     }
    //     return nums.size();
    // }
};
