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
     int minDiff = Integer.MAX_VALUE;
     int val = 0;
     public int minDiffInBST(TreeNode root) {
         dfs(root);
         return minDiff;
     }
     public void dfs(TreeNode root){
         if(root == null) return;
         
         dfs(root.left);
         if(val == 0){
             val = root.val;
         }
         else{
             minDiff = Math.min(minDiff, Math.abs(val - root.val));
             val = root.val;
         }
         dfs(root.right);
     }
 }
