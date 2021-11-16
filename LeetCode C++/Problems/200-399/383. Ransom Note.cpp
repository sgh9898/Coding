class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // can use array alternatively
        unordered_map<char, int> map;
        for (char ch : ransomNote) {
            map[ch]++;
        }
        for (char ch : magazine) {
            if (map.count(ch)) {
                map[ch]--;
                if (map[ch] < 0) {
                    return false;
                } else if (map[ch] == 0) {
                    map.erase(ch);
                }
            }
        }
        return map.empty();
    }
};
