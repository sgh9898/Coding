class Solution {
    public int findJudge(int n, int[][] trust) {
    	if (trust.length == 0 && n == 1) {
    		return 1;
    	}
    	HashMap<Integer, Integer> trusted = new HashMap<>();
    	// iteration
    	for (int i = 0; i < trust.length; i++) {
    		int first = trust[i][0];
    		int second = trust[i][1];
    		trusted.put(first, trusted.getOrDefault(first, 0) - 1);
			trusted.put(second, trusted.getOrDefault(second, 0) + 1);
    	}

    	for (int i : trusted.keySet()) {
    		if (trusted.get(i) == n - 1) {
    			return i;
    		}
    	}
    	return -1;
    }
}