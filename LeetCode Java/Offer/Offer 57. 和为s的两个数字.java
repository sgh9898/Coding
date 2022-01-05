class Solution {
	public int[] twoSum(int[] nums, int target) {
    	int lt = 0, rt = nums.length - 1;
    	while (lt < rt) {
    		if (nums[lt] + nums[rt] == target) {
    			return new int[]{nums[lt], nums[rt]};
    		} else if (nums[lt] + nums[rt] < target) {
    			lt++;
    		} else {
    			rt--;
    		}
    	}
    	return new int[]{};
    }

    // public int[] twoSum(int[] nums, int target) {
    // 	HashSet<Integer> set = new HashSet<>();
    // 	for (int num : nums) {
    // 		if (set.contains(num)) {
    // 			return new int[]{target - num, num};
    // 		} else {
    // 			set.add(target - num);
    // 		}
    // 	}
    // 	return new int[]{};
    // }
}