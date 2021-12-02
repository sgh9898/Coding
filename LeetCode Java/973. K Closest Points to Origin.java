class Solution {
    public int[][] kClosest(int[][] points, int k) {
        // furthest points at the top
        PriorityQueue<int[]> closest = new PriorityQueue<>(new Comparator<int[]>(){
            public int compare(int[] first, int[] second) {
                return second[1] - first[1];
            }
        });

        // calculate and compare distance
        for (int i = 0; i < points.length; i++) {
            int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            // more than k points
            if (closest.size() == k) {
                if (closest.peek()[1] > dis) {
                    closest.poll();
                    closest.offer(new int[]{i, dis});
                }
            } else {
                closest.offer(new int[]{i, dis});
            }
        }
        int[][] res = new int[k][2];
        for (int i = 0; i < k; i++) {
            int idx = closest.poll()[0];
            res[i][0] = points[idx][0];
            res[i][1] = points[idx][1];
        }
        return res;
    }
}