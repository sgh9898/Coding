class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	if (nums.empty()) {
    		return 0;
    	}
    	int cnt = 1, max_length = 1;
    	for (int i = 1; i < nums.size(); i++) {
    		if (nums[i] == nums[i - 1] + 1) {
    			cnt++;
    			max_length = max(cnt, max_length);
    		} else if (nums[i] == nums[i - 1]) {
    			continue;
    		} else {
    			cnt = 1;
    		}
    	}
    	return max_length;
    }
};