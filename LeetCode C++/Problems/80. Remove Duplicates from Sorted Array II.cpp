class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool del = false;
        for (int i = 1; i < nums.size(); i++) {
            // duplicates
            if (nums[i] == nums[i - 1]) {
                // 2nd
                if (del == false) {
                    del = true;
                // more than 2
                } else {
                    nums.erase(nums.begin() + i);
                    i--;
                }
            } else {
                del = false;
            }
        }
        return nums.size();
    }
};
