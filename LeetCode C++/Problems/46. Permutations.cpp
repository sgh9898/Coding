class Solution {
public:
    void Helper(vector<int>& nums, vector<vector<int>>& ans, int pos) {
        // out of bounds
        if (pos >= nums.size()) return;
        // save
        if (pos == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[pos], nums[i]);
            Helper(nums, ans, pos);
            swap(nums[pos], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        Helper(nums, ans, 0);
        return ans;
    }
};
