class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        int l = pow(2, N - 1);
        if (K <= l/2) {
            return kthGrammar( N - 1 , K);
        } else {
            return 1 - kthGrammar( N - 1, K - l/2);
        }
    }
};
