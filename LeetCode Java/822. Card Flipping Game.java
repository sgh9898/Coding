class Solution {
    public int flipgame(int[] fronts, int[] backs) {
        Set<Integer> excluded = new HashSet<>();
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < fronts.length; i++) {
            if (fronts[i] == backs[i]) {
                excluded.add(fronts[i]);
            }
        }
        for (int i = 0; i < fronts.length; i++) {
            if (fronts[i] != backs[i]) {
                if (!excluded.contains(fronts[i]) && fronts[i] < min) {
                    min = fronts[i];
                }
                if (!excluded.contains(backs[i]) && backs[i] < min) {
                    min = backs[i];
                }
            }
        }
        if (min == Integer.MAX_VALUE) {
            return 0;
        } else {
            return min;
        }
    }
}