class Solution {
public:
    int countValidWords(string sentence) {
        istringstream ss(sentence);
        string word;
        int cnt = 0;
        while (ss >> word) {
        	if (isValid(word)) {
        		cnt++;
        	}
        }
        return cnt;
    }

    bool isValid(const string& word) {
        int n = word.length();
        bool has_hyphens = false;
        for (int i = 0; i < n; i++) {
            if (word[i] >= '0' && word[i] <= '9') {
                return false;
            } else if (word[i] == '-') {
                if (has_hyphens == true || i == 0 || i == n - 1 || !islower(word[i - 1]) || !islower(word[i + 1])) {
                    return false;
                }
                has_hyphens = true;
            } else if (word[i] == '!' || word[i] == '.' || word[i] == ',') {
                if (i != n - 1) {
                    return false;
                }
            }
        }
        return true;
    }
};