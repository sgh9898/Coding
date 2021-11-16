class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> paren;
        string str_out;
        int unmatched = 0;
        for (auto c : S) {
            if (c == '(') {
                if (unmatched != 0) {       // not the outmost
                    str_out += c;
                }
                unmatched++;
            } else if (c == ')') {
                unmatched--;
                if (unmatched != 0) {
                    str_out += c;
                }
            }
        }
        return str_out;
    }
};
