class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> res;
        if (nums.empty())    return 0;

        for (int n : nums) {
            // check duplicates
            bool same = false;
            for (int m : res) {
                if (n == m) {
                    same = true;
                    break;
                }
            }

            if (!same) {
                if (res.size() < 3) {           // get 3 nums
                    res.push_back(n);
                    sort(res.begin(),res.end());
                } else if (n > res[0]) {        // normal cases
                    res.push_back(n);
                    sort(res.begin(),res.end());
                    res.erase(res.begin());
                }
            }
        }

        if (res.size() < 3) {
            return res[res.size()-1];
        } else {
            return res[0];
        }
    }
};
