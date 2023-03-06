class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int src_color = image[sr][sc];
        if (src_color == color) {
            return image;
        }
        // init
        int i_max = image.length;
        int j_max = image[0].length;
        Queue<Integer> i_que = new LinkedList<>();
        Queue<Integer> j_que = new LinkedList<>();
        i_que.offer(sr);
        j_que.offer(sc);

        // mian loop
        while (i_que.peek() != null) {
            int curr_i = i_que.poll();
            int curr_j = j_que.poll();

            // fill
            if (image[curr_i][curr_j] == src_color) {
                image[curr_i][curr_j] = color;
                // check neighbor
                if (curr_i + 1 < i_max) {
                    i_que.offer(curr_i + 1);
                    j_que.offer(curr_j);
                }
                if (curr_i - 1 >= 0) {
                    i_que.offer(curr_i - 1);
                    j_que.offer(curr_j);
                }
                if (curr_j + 1 < j_max) {
                    i_que.offer(curr_i);
                    j_que.offer(curr_j + 1);
                }
                if (curr_j - 1 >= 0) {
                    i_que.offer(curr_i);
                    j_que.offer(curr_j - 1);
                }
            }
        }
        return image;
    }
}