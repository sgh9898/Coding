class Solution {
public:
    string reverseWords(string s) {
        stringstream str_in(s);
        string temp, result;
        while (str_in >> temp) {
            reverse(temp.begin(), temp.end());
            result += temp + " ";
        }
        result.pop_back();
        return result;
    }
};
