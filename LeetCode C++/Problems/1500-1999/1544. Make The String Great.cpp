class Solution {
public:
    string makeGood(string s) {
        string str_out;
        for (char ch: s) {
            if (!str_out.empty() && tolower(str_out.back()) == tolower(ch) && str_out.back() != ch) {
                str_out.pop_back();
            }
            else {
                str_out.push_back(ch);
            }
        }
        return str_out;
    }
};
