class Solution {
    public int countSubIslands(int[][] grid1, int[][] grid2) {
    	int cnt = 0;
    	for (int i = 0; i < grid2.length; i++) {
    		for (int j = 0; j < grid2[0].length; j++) {
    			if (grid2[i][j] == 1) {
    				if (isSubIsland(grid1, grid2, i, j)) {
    					cnt++;
    				}
    			}
    		}
    	}
    	return cnt;
    }

    private boolean isSubIsland(int[][] grid1, int[][] grid2, int i, int j) {
    	// out of bound
    	if (i < 0 || i >= grid1.length || j < 0 || j >= grid1[0].length) {
    		return true;
    	} else if (grid2[i][j] == 1) {
    		// sub island
    		if (grid1[i][j] == 1) {
    			// mark as read
    			grid2[i][j] = 2;
    			boolean check_up = isSubIsland(grid1, grid2, i - 1, j);
    			boolean check_down = isSubIsland(grid1, grid2, i + 1, j);
    			boolean check_left = isSubIsland(grid1, grid2, i, j - 1);
    			boolean check_right = isSubIsland(grid1, grid2, i, j + 1);
    			return check_up && check_down && check_left && check_right;
    		} else {
    			return false;
    		}
    	} else if (grid2[i][j] == 0 || grid2[i][j] == 2) {
    		return true;
    	}
    	return false;
    }
}