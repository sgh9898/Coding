class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lt = 0, rt = arr.size();
        while (lt < rt) {
            int mid = (lt + rt) >> 1;
            if (arr[mid] - mid >= k + 1) {
                rt = mid;
            } else {
                lt = mid + 1;
            }
        }
        return lt + k;
    }
};
