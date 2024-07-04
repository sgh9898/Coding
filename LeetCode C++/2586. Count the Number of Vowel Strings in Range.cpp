class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
    	int cnt = 0;
    	unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'}; 
        for (int i = left; i <= right; i++) {
        	int len = words[i].size();
        	if (vowels.count(words[i][0]) && vowels.count(words[i][len - 1])) {
        		cnt++;
        	}
        }
        return cnt;
    }
};