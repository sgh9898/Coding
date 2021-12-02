class Solution {
    public int[] topKFrequent(int[] nums, int k) {
    	HashMap<Integer, Integer> freqMap = new HashMap<>();
    	for (int num : nums) {
    		freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
    	}
    	PriorityQueue<int[]> freqQue = new PriorityQueue<>(new Comparator<int[]>(){
    		public int compare(int[] first, int[] second) {
    			return first[1] - second[1];
    		}
    	});
    	for (Map.Entry<Integer, Integer> entry : freqMap.entrySet()) {
    		int num = entry.getKey(), freq = entry.getValue();
    		if (freqQue.size() == k) {
                if (freqQue.peek()[1] < freq) {
                    freqQue.poll();
                    freqQue.offer(new int[]{num, freq});
                }
            } else {
                freqQue.offer(new int[]{num, freq});
            }
    	}
    	int[] res = new int[k];
    	for (int i = k - 1; i >= 0; i--) {
    		res[i] = freqQue.poll()[0];
    	}
    	return res;
    }
}