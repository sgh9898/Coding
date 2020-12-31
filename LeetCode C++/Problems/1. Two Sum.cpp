class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map<target-num[i],i>
        std::unordered_map<int, int> map;
        std::vector<int> result;

        for (int i=0;i<nums.size();i++) {
            // no matches
            if (map.find(nums[i]) == map.end()) {
                map[target-nums[i]] = i;
            } else {
                // matches
                result.push_back(map[nums[i]]);
                result.push_back(i);
                break;
            }
        }
        return result;
    }
};
