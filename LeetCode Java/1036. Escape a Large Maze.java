class Solution {

	int BORDER = 1000000;
    int[][] DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {

    	// source/target 是否被 blocks 包围
        return bfs(blocked, source, target) && bfs(blocked, target, source);
    }


    boolean bfs(int[][] blocked, int[] source, int[] target) {
        Set<Integer> visited = new HashSet<>();
        
        for (int[] block : blocked) {
        	visited.add(BORDER * block[0] + block[1]);
        }
        visited.add(BORDER * source[0] + source[1]);

        Queue<int[]> queue = new ArrayDeque<>();
        queue.offer(source);

        while (!queue.isEmpty()) {
            int size = queue.size();

            // 能访问的点超过了 block 围成的最大面积, 必连通
            if (size >= blocked.length) return true;

            while (--size >= 0) {
                int[] p = queue.poll();

                // 遍历四周连接点
                for (int[] d : DIRECTIONS) {
                    int x = p[0] + d[0], y = p[1] + d[1];
                    // 出界
                    if (x < 0 || x >= BORDER || y < 0 || y >= BORDER) continue;
                    // source/target 连通
                    if (x == target[0] && y == target[1]) return true;
                    // 添加新的有效点
                    if (visited.add(BORDER * x + y)) {
                    	queue.offer(new int[]{x, y});
                    }
                }
            }
        }
        return false;
    }
}