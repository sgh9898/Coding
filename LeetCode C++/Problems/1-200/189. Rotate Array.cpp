class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k % nums.size() == 0 || nums.size() <= 1)     return;

        int temp = 0,orig = 0,pos = 0;
        for (int cnt = 0;cnt < nums.size();cnt++) {     // loop n times
            swap(nums[pos],temp);
            pos = (pos + k) % nums.size();      // next
            if (pos == orig) {                  // shift by 1 once go back to the origin
                swap(nums[pos],temp);
                pos++;
                orig++;
                temp = 0;
            }

        }

        return;
    }
};
