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

    void Backtracking(vector<string>& subset, string& src, int index, int& min_cut) {
        if (index >= src.length()) {
            min_cut = min(min_cut, (int)subset.size() - 1);
            return;
        }
        for (int i = index; i < src.length(); i++) {
            string temp = src.substr(index, i + 1 - index);
            if (IsPalindrome(temp)) {
                subset.push_back(temp);
                Backtracking(subset, src, i + 1, min_cut);
                subset.pop_back();
            } else {
                continue;
            }
        }
    }

    int minCut(string s) {
        vector<string> subset;
        int min_cut = INT_MAX;
        Backtracking(subset, s, 0, min_cut);
        return min_cut;
    }
};
