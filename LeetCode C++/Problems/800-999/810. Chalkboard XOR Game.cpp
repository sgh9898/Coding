class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int n = nums.size(), x = 0;
        if(n % 2 == 0) return true;
        for(int& num : nums)
            x ^= num;
        return x == 0;
    }
};
