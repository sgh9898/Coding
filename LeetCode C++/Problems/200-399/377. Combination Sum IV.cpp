class Solution {
public:
    void Backtracking(int& res, int& curr, vector<int>& nums, int target, int idx) {
        if (curr > target) {
            return;
        } else if (curr == target) {
            res++;
            return;
        } else {
            for (int i = idx; i < nums.size(); i++) {
                curr += nums[i];
                Backtracking(res, curr, nums, target, idx);
                curr -= nums[i];
            }
        }
    }

    int combinationSum4(vector<int>& nums, int target) {
        int res = 0, curr = 0;
        Backtracking(res, curr, nums, target, 0);
        return res;
    }
};
