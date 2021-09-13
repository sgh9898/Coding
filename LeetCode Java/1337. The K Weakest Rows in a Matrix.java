class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int col_limit = mat.length, row_limit = mat[0].length;
        List<int[]> power = new ArrayList<int[]>();
        PriorityQueue<int[]> sorted = new PriorityQueue<int[]>((a,b)->{
            // [number of 1's, index]
            if (a[0] != b[0]) {
                return a[0] - b[0];
            }
            return a[1] - b[1];
        });

        for (int i = 0; i < col_limit; i++) {
            // binary search to find the rightmost 1
            int lt = 0, rt = row_limit - 1, pos = -1;
            while (lt <= rt) {
                int mid = lt + (rt - lt) / 2;
                if (mat[i][mid] >= 1) {
                    pos = mid;
                    lt = mid + 1;
                } else {
                    rt = mid - 1;
                }
            }
            power.add(new int[]{pos + 1, i});
        }

        for (int[] pair : power ) {
            sorted.offer(pair);
        }

        int ans[] = new int[k];
        for (int i = 0; i < k; i++) {
            ans[i] = sorted.poll()[1];
        }
        return ans;
    }
}
