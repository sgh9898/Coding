class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        string result;
        // outer loop
        int cyl = 2 * numRows - 2;
        int cur_row;
        for (cur_row = 0; cur_row < numRows; cur_row++) {
            // inner loop
            for (int i = 0; i + cur_row < s.size(); i += cyl) {
                // down
                result += s[i+cur_row];
                // up
                if (cur_row != 0 && cur_row != numRows - 1) {
                    if (i + cyl - cur_row < s.size()) {
                        result += s[i+cyl-cur_row];
                    }
                }
            }
        }
        return result;
    }
};
