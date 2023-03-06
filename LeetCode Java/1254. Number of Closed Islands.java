class Solution {
    public int closedIsland(int[][] grid) {
    	// init
    	int i_max = grid.length;
    	int j_max = grid[0].length;
    	int cnt = 0;

    	// count number
    	for (int i = 0; i < i_max; i++) {
    		for (int j = 0; j < j_max; j++) {
    			if (grid[i][j] == 0) {
                    if (isClosed(grid, i, j)) {
                        cnt++;
                    }
    			}
    		}
    	}
    	return cnt;
    }

    private boolean isClosed(int[][] grid, int i, int j) {
    	// out
    	if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length) {
    		return false;
    	}

    	// check island
    	if (grid[i][j] == 0) {
    		// mark as read
    		grid[i][j] = 2;
    		// check
    		boolean check_up = isClosed(grid, i - 1, j);
            boolean check_bot = isClosed(grid, i + 1, j);
            boolean check_lt = isClosed(grid, i, j - 1);
            boolean check_rt = isClosed(grid, i, j + 1);
            return check_up && check_bot && check_lt && check_rt;
    	} else if (grid[i][j] == 1) {
	    	// water
    		return true;
    	} else if (grid[i][j] == 2) {
            // checked
            return true;
        }
    	return false;
    }
}