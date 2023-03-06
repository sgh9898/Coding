class Solution {
    public int maxAreaOfIsland(int[][] grid) {
    	// init
    	int i_max = grid.length;
    	int j_max =  grid[0].length;
    	int max_area = 0;
    	for (int i = 0; i < i_max; i++) {
    		for (int j = 0; j < j_max; j++) {
    			int area = expand(grid, i, j, 0);
    			max_area = Math.max(area, max_area);
    		}
    	}
    	return max_area;
    }

    private int expand(int[][] grid, int curr_i, int curr_j, int area) {
    	// invalid coordinates
    	if (curr_i < 0 || curr_i >= grid.length || curr_j < 0 || curr_j >= grid[0].length) {
    		return area;
    	}

    	// island
    	if (grid[curr_i][curr_j] == 1) {
    		// mark as read
    		area++;
    		grid[curr_i][curr_j] = 2;
    		// expand
    		area = expand(grid, curr_i - 1, curr_j, area);
    		area = expand(grid, curr_i + 1, curr_j, area);
    		area = expand(grid, curr_i, curr_j - 1, area);
    		area = expand(grid, curr_i, curr_j + 1, area);
    	}
    	return area;
    }
}