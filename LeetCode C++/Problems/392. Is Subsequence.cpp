class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_idx, t_idx = 0;
        // target character
        for (s_idx = 0; s_idx < s.size(); s_idx++) {
            // range
            int j;
            for (j = t_idx; j < t.size(); j++) {
                if (s[s_idx] == t[j]) {
                    t_idx = j;  // found
                    break;
                }
            }
            // not found
            if (j == t.size()) {
                return false;
            }
            t_idx++;
        }
        return true;
    }
};
