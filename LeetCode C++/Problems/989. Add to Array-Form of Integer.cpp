class Solution {
public:
    vector<int> addToArrayForm(vector<int> &A, int K) {
        vector<int> res;
        int n = A.size();
        for (int i = n - 1; i >= 0; --i) {
            int sum = A[i] + K % 10;
            K /= 10;
            if (sum >= 10) {
                K++;
                sum -= 10;
            }
            res.push_back(sum);
        }
        for (; K > 0; K /= 10) {
            res.push_back(K % 10);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
