class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res(A.size(), false);
        int units = 0;
        for (int i = 0; i < A.size(); i++) {
            // use units digit to check divisibility
            units = (units * 2 + A[i]) % 10;
            if (units % 5 == 0) {
                A[i] = true;
            }
        }
        return res;
    }
};
