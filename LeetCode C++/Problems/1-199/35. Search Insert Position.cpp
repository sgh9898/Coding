class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lt = 0,rt = nums.size()-1;
        while (lt <= rt) {
            int mid = lt + (rt-lt)/2;
            if (target > nums[mid])
                lt = mid+1;
            else rt = mid-1;
        }
        return lt;
    }
};
