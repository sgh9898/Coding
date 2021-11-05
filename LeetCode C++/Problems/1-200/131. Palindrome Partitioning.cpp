class Solution {
public:
    bool IsPalindrome(const string& str) {
        int lt = 0, rt = str.length() - 1;
        while (lt <= rt) {
            if (str[lt] != str[rt]) {
                return false;
            } else {
                lt++;
                rt--;
            }
        }
        return true;
    }

    void Backtracking(vector<vector<string>>& res, vector<string>& subset, string& src, int index) {
        if (index >= src.length()) {
            res.push_back(subset);
            return;
        }
        for (int i = index; i < src.length(); i++) {
            string temp = src.substr(index, i + 1 - index);
            if (IsPalindrome(temp)) {
                subset.push_back(temp);
                Backtracking(res, subset, src, i + 1);
                subset.pop_back();
            } else {
                continue;
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> subset;
        Backtracking(res, subset, s, 0);
        return res;
    }
};
