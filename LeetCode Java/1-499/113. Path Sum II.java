/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
	public List<List<Integer>> res = new LinkedList<>();

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
    	List<Integer> path = new LinkedList<>();
    	recursion(root, path, targetSum);
    	return res;
    }

    private void recursion(TreeNode curr, List<Integer> path, int targetSum) {
    	// terminate
    	if (curr == null) {
    		return;
    	}
    	// leaf
    	if (curr.left == null && curr.right == null) {
    		// valid
    		if (curr.val == targetSum) {
    			path.add(curr.val);
    			res.add(new LinkedList<Integer>(path));
    			path.remove(path.size() - 1);
    		}
    	} else {
			path.add(curr.val);
			recursion(curr.left, path, targetSum - curr.val);
			recursion(curr.right, path, targetSum - curr.val);
			path.remove(path.size() - 1);
    	}
    }
}