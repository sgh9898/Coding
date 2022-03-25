class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
    	int side_len = 0, cnt = 0;

    	// get the side length of the largest square
        for (int i = 0; i < rectangles.size(); i++) {
        	vector<int> temp = rectangles[i];
        	int temp_len = min(temp[0], temp[1]);

        	if (temp_len > side_len) {
        		side_len = temp_len;
        		cnt = 1;
        	} else if (temp_len == side_len) {
        		cnt++;
        	}
        }

        return cnt;
    }
};