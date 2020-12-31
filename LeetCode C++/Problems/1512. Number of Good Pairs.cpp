class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_multiset<int> mset;
        int res = 0;
        for(auto n : nums){
            res += mset.count(n);
            mset.insert(n);
        }
        return res;
    }
};
