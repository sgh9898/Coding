class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, bool> dic;
        for(char c : s)
            dic[c] = dic.find(c) == dic.end();
        for(char c : s)
            if(dic[c]) return c;
        return ' ';
    }
};