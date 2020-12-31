class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int cur_num = 1;
        vector<string> vec_str;
        for (int num : target) {
            while (num != cur_num) {
                vec_str.push_back("Push");
                vec_str.push_back("Pop");
                cur_num++;
            }
            vec_str.push_back("Push");
            cur_num++;
        }
        return vec_str;
    }
};
