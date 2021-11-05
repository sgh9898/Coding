class Solution {
public:
    string getPermutation(int n, int k) {
        // construction
        vector<int> vec;
        for (int i = 1;i <= n;i++) {
            vec.push_back(i);
        }

        for(int i = 1;i<k-1;i++) {
            next_permutation(vec.begin(),vec.end());
        }
        string str_out;
        for (int num : vec) {
            str_out += to_string(num);
        }
        return str_out;
    }
};
