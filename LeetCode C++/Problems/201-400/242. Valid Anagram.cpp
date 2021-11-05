class Solution {
public:
    bool isAnagram(string s, string t) {
        // can use array alternatively
        unordered_map<char, int> map;
        for (char ch : s) {
            map[ch]++;
        }
        for (char ch : t) {
            if (map.count(ch)) {
                map[ch]--;
                if (map[ch] < 0) {
                    return false;
                } else if (map[ch] == 0) {
                    map.erase(ch);
                }
            } else {
                return false;
            }
        }
        return map.empty();
    }
};
