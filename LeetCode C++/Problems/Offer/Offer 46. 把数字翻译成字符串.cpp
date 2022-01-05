class Solution {
public:
    int translateNum(int num) {
    	if (num < 10) {
    		return 1;
    	} else if (num % 100 >= 10 && num % 100 <= 25) {
    		return translateNum(num / 100) + translateNum(num/10);
    	} else {
    		return translateNum(num / 10);
    	}
    }
};