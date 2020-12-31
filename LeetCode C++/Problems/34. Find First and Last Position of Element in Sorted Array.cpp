class Solution {
public:
    void BS(vector<int>& nums, int target, int lt, int rt, int& first, int &last) {
        if (lt > rt) return;
        int mid = (lt + rt)/2;
        if (nums[mid] == target) {
            first = min(first, mid);
            last = max(last, mid);
        }
        BS(nums, target, mid + 1, rt, first, last);
        BS(nums, target, lt, mid - 1, first, last);
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int first = INT_MAX, last = -1;
        BS(nums, target, 0, nums.size() - 1, first, last);
        if (last == -1) first = -1;
        vector<int> vec = {first, last};
        return vec;
    }
};
