class Solution {
public:
    string reverseOnlyLetters(string s) {
    	int lt = 0, rt = s.size() - 1;
    	while (true) {
    		// left
    		while(lt < rt && !isalpha(s[lt])) {
    			lt++;
    		}

    		// right
    		while(rt > lt && !isalpha(s[rt])) {
    			rt--;
    		}

    		// swap
    		if (lt < rt) {
    			swap(s[lt], s[rt]);
    			lt++;
    			rt--;
    		} else {
    			break;
    		}
    	}
    	return s;
    }
};