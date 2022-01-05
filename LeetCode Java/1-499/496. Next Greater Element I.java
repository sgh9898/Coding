class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> stk = new Stack<>();
        HashMap<Integer, Integer> map = new HashMap<>();

        // build the map of next greater elements
        for (int i = 0; i < nums2.length; i++) {
        	int temp = nums2[i];
        	// store next greater elements
        	while (!stk.isEmpty() && temp > stk.peek()) {
        		map.put(stk.peek(), temp);
                stk.pop();
        	}
        	stk.add(temp);
        }

        // return value
        for (int i = 0; i < nums1.length; i++) {
        	nums1[i] = map.getOrDefault(nums1[i], -1);
        }

        return nums1;
    }
}