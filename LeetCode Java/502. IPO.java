class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = capital.length;
        int[][] arr = new int[n][2];

        for (int i = 0; i < n; i++) {
            // arr[capital][profits]
            arr[i][0] = capital[i];
            arr[i][1] = profits[i];
        }
        // capital in ascending order
        Arrays.sort(arr, (a, b) -> a[0] - b[0]);

        // profits in descending order
        PriorityQueue<Integer> pq = new PriorityQueue<Integer> ((x, y) -> y - x);

        int curr = 0;
        for (int i = 0; i < k; i++) {
            while (curr < n && arr[curr][0] <= w) {
                pq.offer(arr[curr][1]);
                curr++;
            }
            if (!pq.empty()) {
                w += pq.poll();
            } else {
                break;  // Stop if there is no more projects.
            }
        }
        return w;
    }
}
