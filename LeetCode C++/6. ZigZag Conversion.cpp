class Solution {
public:
    string convert(string s, int numRows) {
    	if (numRows == 1) {
    		return s;
    	}
    	vector<vector<int>> zigzag(numRows);
    	int curr_row = 0, cnt = 0;
    	bool upward = false;

    	while (cnt < s.size()) {
    		zigzag[curr_row].push_back(s[cnt]);
    		if (upward) {
    			if (curr_row > 0) {
    				curr_row--;
    			} else {
    				curr_row++;
    				upward = false;
    			}
    		} else {
    			if (curr_row < numRows - 1) {
    				curr_row++;
    			} else {
    				curr_row--;
    				upward = true;
    			}
    		}
    		cnt++;
    	}
    	string res = "";
    	for (int i = 0; i < zigzag.size(); i++) {
    		for (int j = 0; j < zigzag[i].size(); j++) {
    			res += zigzag[i][j];
    		}
    	}
    	return res;
    }
};