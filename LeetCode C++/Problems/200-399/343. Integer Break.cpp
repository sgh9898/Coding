class Solution {
public:
    int integerBreak(int n) {
        int pre = 1, curr = 1, max_product = 1;
        for (int k = 2; k < n; k++) {
            curr = ProductOfK(n, k);
            if (curr < pre) {
                return max_product;
            } else {
                max_product = max(max_product, curr);
                pre = max_product;
            }
        }
        return max_product;
    }

    int ProductOfK(int n, int k) {
        int base = n / k, num_base = k - (n - base * k);
        return pow(base, num_base) * pow(base + 1, k - num_base);
    }
};
