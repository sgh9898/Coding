class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window;
        for (size_t i = 0; i < nums.size(); i++) {
            if (i > k) {
                window.erase((long)nums[i - k - 1]);
            }
            auto pos = window.lower_bound((long)nums[i] - t);  // y ≥ x - t ==> y - x ≥ -t
            if (pos != window.end() && *pos - nums[i] <= t) {  // y - x ≤ t
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};
