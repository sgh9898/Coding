class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> nums_map;
        for (int i = 0;i < nums.size();i++) {
            if (!nums_map.insert(1,2)) {
                if (i - nums_map[i] <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};
