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
	private List<Integer> res = new ArrayList<>();

    public List<Integer> rightSideView(TreeNode root) {
    	recursion(root, 0);
    	return res;
    }

    private void recursion(TreeNode curr, int depth) {
    	// terminate
    	if (curr == null) {
    		return;
    	}
    	// new right node
    	if (res.size() <= depth) {
    		res.add(curr.val);
    	}
    	recursion(curr.right, depth + 1);
    	recursion(curr.left, depth + 1);
    }
}