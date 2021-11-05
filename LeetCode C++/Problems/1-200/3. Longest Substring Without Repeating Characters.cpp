class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int buffer[256] {0};

        if (s.size() <= 1) {
            return s.size();
        }

        int start = 0,end = 0,max_len = 0;
        for (int i = 0;i < s.size();i++) {
            // mark
            buffer[s[i]]++;
            // repeat elements
            if (buffer[s[i]] > 1) {
                end = i - 1;
                while (buffer[s[i]] > 1 && start <= end) {
                    // clear marks from the start to the repeating elements
                    buffer[s[start]]--;
                    start++;
                }
            } else {
                end = i;
            }
            max_len = max(max_len,end - start + 1);
        }
        return max_len;
    }
};
