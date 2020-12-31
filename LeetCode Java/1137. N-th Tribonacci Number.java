class Solution {
    int[] map;

    Solution() {
        map = new int[38];
        map[0] = 0;
        map[1] = 1;
        map[2] = 1;
        for (int i = 3; i < map.length; i++) {
            map[i] = -1;
        }
    }
    public int tribonacci(int n) {
        if (map[n] != -1) {
            return map[n];
        } else {
            int result = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
            map[n] = result;
            return result;
        }
    }
}
