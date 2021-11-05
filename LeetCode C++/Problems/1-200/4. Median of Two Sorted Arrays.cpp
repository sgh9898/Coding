class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (auto n : nums2) {
            nums1.push_back(n);
        }
        sort(nums1.begin(), nums1.end());
        int m = nums1.size();
        double res = 0;
        if (m % 2 == 0) {
            res = (nums1[m/2 - 1] + nums1[m/2]);
            res = res/2;
        } else {
            res = nums1[m/2];
        }
        return res;
    }
};
