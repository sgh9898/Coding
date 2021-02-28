class Solution {
public:
    bool check(unordered_map<char, int>& mp, int k) {
        for (auto [_, cnt] : mp) {
            if (cnt < k) {
                return false;
            }
        }
        return true;
    }

    int longestSubstring(string s, int k) {
        int len = s.length();
        if (len < k) return 0;

        int count[26] = {0};
        for (int i = 0; i < len; ++i) {
            count[s[i] - 'a']++;
        }

        int maxLen = 0;

        unordered_map<char, int> mp;

        vector<string> substrings;
        int left = 0;
        for (int i = 0; i < len; ++i) {
            if (count[s[i] - 'a'] < k) {
                substrings.push_back(s.substr(left, i-left));
                left = i+1;
            }
        }

        string tmp = s.substr(left);
        substrings.push_back(tmp);

        if (left == 0) {
            return (int)s.length();
        }

        for (int i = 0; i < substrings.size(); ++i) {
            int value = longestSubstring(substrings[i], k);
            // cout << substrings[i] << " " << value << endl;
            maxLen = max(value, maxLen);
        }

        // cout << "==============" << endl;

        return maxLen;
    }
};
