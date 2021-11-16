class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map<target-num[i],i>
        unordered_map<int, int> map;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // no matches, record complementary number and index
            if (map.find(nums[i]) == map.end()) {
                map[target-nums[i]] = i;
            } else {
                // matches, record indices
                result.push_back(map[nums[i]]);
                result.push_back(i);
                break;
            }
        }
        return result;
    }
};
