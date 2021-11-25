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
    private int sum;

    protected int Tilt(TreeNode node) {
        if (node == null) {
            return 0;
        }
        int lt = this.Tilt(node.left);
        int rt = this.Tilt(node.right);
        int tilt = Math.abs(lt - rt);
        this.sum += tilt;
        return node.val + lt + rt;
    }

    public int findTilt(TreeNode root) {
        this.sum = 0;
        this.Tilt(root);
        return this.sum;
    }
}
