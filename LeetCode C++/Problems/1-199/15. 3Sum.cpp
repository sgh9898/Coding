class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        // first
        for (int first = 0;first < n;first++) {
            if (first > 0 && nums[first] == nums[first-1]) {    // skip duplicates
                continue;
            }
            // third
            int third = n-1, target = -nums[first];
            // second
            for (int second = first+1;second < n;second++) {
                if (second > first+1 && nums[second] == nums[second-1]) {   // skip duplicates
                    continue;
                }

                // move third
                while (second < third && nums[second] + nums[third] > target) {
                    third--;
                }

                // break
                if (second == third) {
                    break;
                }

                // found
                if (nums[second] + nums[third] == target) {
                    ans.push_back(vector<int> {nums[first],nums[second],nums[third]});
                }
            }
        }
        return ans;
    }
};
