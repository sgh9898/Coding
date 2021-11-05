class Solution {
public:
    void Backtracking(unordered_map<char, string>& phone_map, vector<string>& res, string& combination, string& digits, int idx) {
        if (combination.length() >= digits.length()) {
            res.push_back(combination);
            return;
        } else {
            string letters = phone_map[digits[idx]];
            for (char letter : letters) {
                combination.push_back(letter);
                Backtracking(phone_map, res, combination, digits, idx + 1);
                combination.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string combination;
        unordered_map<char, string> phone_map{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        if (digits.empty()) {
            return res;
        }
        Backtracking(phone_map, res, combination, digits, 0);
        return res;
    }
};
