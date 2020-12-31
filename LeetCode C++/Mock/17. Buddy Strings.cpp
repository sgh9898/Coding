class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) return false;
        unordered_set<char> letters;
        int diff1 = -1, diff2 = -1;
        for (size_t i = 0; i < A.length(); i++) {
            letters.insert(A[i]);
            if (A[i] != B[i]) {
                if (diff1 != -1 && diff2 != -1) return false;
                else if (diff1 != -1) diff2 = i;
                else diff1 = i;
            }
        }
        if (diff1 != -1 && diff2 != -1) {
            return A[diff1] == B[diff2] && A[diff2] == B[diff1];
        } else if (diff1 != -1) {
            return false;
        } else {
            return letters.size() < A.length();
        }
    }
};
