class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size()-1;
        int i1 = m-1,i2 = n-1;
        while (i2 >= 0) {
            if (i1 >= 0 && nums1[i1] >= nums2[i2]) {
                swap(nums1[i1],nums1[i]);
                i1--;
            } else {
                swap(nums2[i2],nums1[i]);
                i2--;
            }
            i--;
        }
    }
};
