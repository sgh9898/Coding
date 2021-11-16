class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1, pos = 1, neg = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1]) {
                pos = neg + 1;
                neg = 1;
            } else if (arr[i] < arr[i - 1]) {
                neg = pos + 1;
                pos = 1;
            } else {
                neg = 1;
                pos = 1;
            }
            res = max(max(res, pos), neg);
        }
        return res;
    }
};
