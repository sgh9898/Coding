class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> kth_largest;
        for (int i = 0; i < nums.size(); i++) {
            kth_largest.push(nums[i]);
            if (kth_largest.size() > k) {
                kth_largest.pop();
            }
        }
        return kth_largest.top();
    }
};
