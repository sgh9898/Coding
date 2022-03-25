class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {

    	// initialization
    	int row_limit = matrix.size(), col_limit = matrix[0].size();
    	vector<int> row_min(row_limit, INT_MAX);
    	vector<int> col_max(col_limit, INT_MIN);

    	// traversal
    	for (int i = 0; i < row_limit; i++) {
    		for (int j = 0; j < col_limit; j++) {
    			// min in the row
    			if (matrix[i][j] < row_min[i]) {
    				row_min[i] = matrix[i][j];
    			}

    			// max in the column
    			if (matrix[i][j] > col_max[j]) {
    				col_max[j] = matrix[i][j];
    			}
    		}
    	}

        // 0 or 1 lucky number
    	vector<int> ans;
        if (*max_element(row_min.begin(), row_min.end()) == *min_element(col_max.begin(), col_max.end())) {
            ans.push_back(*max_element(row_min.begin(), row_min.end()));
        }
    	return ans;
    }
};