class Solution {
public:
    int maxProduct(vector<string>& words) {
    	// 压缩单词至26位bit
    	vector<int> bit_words(words.size(), 0);
    	for (int i = 0; i < words.size(); i++) {
    		for (int j = 0; j < words[i].size(); j++) {
    			// 转换为二进制, 根据1的位置标记字母
    			int current_char = 1 << (words[i][j] - 'a');
    			bit_words[i] = bit_words[i] | current_char;
    		}
    	}


    	int res = 0;
    	for (int i = 0; i < words.size() - 1; i++) {
    		for (int j = i + 1; j < words.size(); j++) {
    			if ((bit_words[i] & bit_words[j]) == 0) {
    				int current_length = words[i].size() * words[j].size();
    				res = max(res, current_length);
    			}
    		}
    	}
    	return res;
    }
};