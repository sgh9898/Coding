class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int limit = s.size();
        n %= limit;
        return s.substr(n, limit - 1) + s.substr(0, n);
    }
};
