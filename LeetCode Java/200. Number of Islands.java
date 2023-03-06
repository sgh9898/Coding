class Solution {
    public int numIslands(char[][] grid) {
    	int cnt = 0;
    	for (int i = 0; i < grid.length; i++) {
    		for (int j = 0; j < grid[0].length; j++) {
    			if (grid[i][j] == '1') {
    				cnt++;
    				markIsland(grid, i, j);
    			}
    		}
    	}
    	return cnt;
    }

    // mark an island as 2
    private void markIsland(char[][] grid, int curr_i, int curr_j) {
    	// check
    	if (curr_i >= grid.length || curr_i < 0 
    		|| curr_j >= grid[0].length || curr_j < 0) {
    		return;
    	}

    	// mark
    	if (grid[curr_i][curr_j] == '1') {
    		grid[curr_i][curr_j] = '2';
    		markIsland(grid, curr_i - 1, curr_j);
    		markIsland(grid, curr_i + 1, curr_j);
    		markIsland(grid, curr_i, curr_j - 1);
    		markIsland(grid, curr_i, curr_j + 1);
    	}
    }
}