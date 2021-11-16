class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if (A[0] > A[n - 1]) {
            // decreasing
            for (int i = 0; i < n - 1; i++) {
                if (A[i] < A[i + 1]) {
                    return false;
                }
            }
        } else if (A[0] < A[n - 1]) {
            //increasing
            for (int i = 0; i < n - 1; i++) {
                if (A[i] > A[i + 1]) {
                    return false;
                }
            }
        } else {
            // equal
            for (int i = 0; i < n - 1; i++) {
                if (A[i] != A[i + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
