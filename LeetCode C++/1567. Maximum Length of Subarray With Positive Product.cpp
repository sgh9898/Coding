class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0, neg = 0, max_len = 0;
        for (int num : nums) {
            if (num > 0) {
                pos++;
                neg = (neg > 0) ?  (neg + 1) : 0;
            } else if (num < 0) {
                int temp_pos = (neg > 0) ? (neg + 1) : 0;
                int temp_neg = pos + 1;
                tie(pos, neg) = {temp_pos, temp_neg};
            } else {
                pos = 0;
                neg = 0;
            }
            max_len = max(max_len, pos);
        }
        return max_len;
    }
};
