class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> tmp_nums = nums;
        tmp_nums.insert(tmp_nums.end(), tmp_nums.begin(), tmp_nums.end());
        stack<int> stk;
        vector<int> nextGreaterNum(tmp_nums.size(), 0);
        for (int i = tmp_nums.size() - 1; i >= 0 ; --i)
        {
            while (!stk.empty() && stk.top() <= tmp_nums[i])
            {
                stk.pop();
            }
            nextGreaterNum[i] = stk.empty() ? -1 : stk.top();
            stk.push(tmp_nums[i]);
        }
        vector<int> ans;
        for (int i = 0; i < len; ++i)
        {
            ans.push_back(nextGreaterNum[i]);
        }
        return ans;
    }
};
