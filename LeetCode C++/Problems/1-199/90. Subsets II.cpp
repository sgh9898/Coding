class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        int size = 0;
        FindSubsets(nums,res,subset,size);
        return res;
    }

private:
    void FindSubsets(vector<int>& nums,vector<vector<int>>& res,vector<int>& subset,int size) {
        res.push_back(subset);  //empty set
        for (int i = size; i < nums.size(); i++) {
            if (i != size && nums[i] == nums[i-1]) {
                continue;
            } else {
                subset.push_back(nums[i]);
                FindSubsets(nums,res,subset,i+1);
                subset.pop_back();
            }
        }
    }
};
