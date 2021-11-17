class Solution {
public:
    int longestPalindrome(string s) {
    	unordered_map<char, int> map;
    	for (char ch : s) {
    		map[ch]++;
    	}
    	int cnt = 0;
    	for (auto iter = map.begin(); iter != map.end(); iter++) {
    		int val = iter->second;
    		if (cnt % 2 == 0) {
    			cnt += val;
    		} else {
    			cnt += val / 2 * 2;
    		}
    	}
    	return cnt;
    }
};