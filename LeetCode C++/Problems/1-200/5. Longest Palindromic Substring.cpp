class Solution {
public:
    pair<int, int> ExpandPalindrome(string& str, int lt, int rt) {
        // even
        if (str[lt] != str[rt]) return make_pair(lt, lt);
        
        int start = lt, end = rt;
        while (lt >= 0 && rt <= str.length() && str[lt] == str[rt]) {
            start = lt;
            end = rt;
            lt--;
            rt++;
        }
        return make_pair(start, end);
    }

    string longestPalindrome(string s) {
        if (s.size() <= 1)    return s;
        pair<int, int> longest(0, 0);
        for (int i = 0; i < s.size(); i++) {
            pair<int, int> odd = ExpandPalindrome(s, i, i);
            pair<int, int> even = ExpandPalindrome(s, i, i+1);
            if (odd.second - odd.first > longest.second - longest.first) {
                longest = odd;
            }
            if (even.second - even.first > longest.second - longest.first) {
                longest = even;
            }
        }
        return s.substr(longest.first, longest.second - longest.first + 1);
    }
};
