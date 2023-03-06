class Solution {
    public int numEnclaves(int[][] grid) {
    	// init
    	int i_max = grid.length;
    	int j_max = grid[0].length;
    	int cnt = 0;

    	// count number
    	for (int i = 0; i < i_max; i++) {
    		for (int j = 0; j < j_max; j++) {
    			if (grid[i][j] == 1) {
                    cnt += getEnclavesNum(grid, i, j, 0);
    			}
    		}
    	}
    	return cnt;
    }

    private int getEnclavesNum(int[][] grid, int i, int j, int cnt) {
    	// out
    	if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length) {
    		return  0;
    	}

    	// count
    	if (grid[i][j] == 1) {
    		// mark as read
    		cnt++;
    		grid[i][j] = 2;
    		// count other cells
    		int cnt_up = getEnclavesNum(grid, i - 1, j, cnt);
    		int cnt_down = getEnclavesNum(grid, i + 1, j, cnt);
    		int cnt_left = getEnclavesNum(grid, i, j - 1, cnt);
    		int cnt_right = getEnclavesNum(grid, i, j + 1, cnt);
    		if (cnt_up == 0 || cnt_down == 0 || cnt_left == 0 || cnt_right == 0) {
    			// invalid
    			return 0;
    		} else {
    			// valid
    			return cnt + cnt_up + cnt_down + cnt_left + cnt_right - 4 * cnt;
    		}
    	} else if (grid[i][j] == 0) {
    		return cnt;
    	} else if (grid[i][j] == 2) {
            // checked
            return cnt;
        }
    	return 0;
    }
}