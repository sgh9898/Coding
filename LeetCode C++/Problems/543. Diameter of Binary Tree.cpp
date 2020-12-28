/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int Helper(TreeNode* curr, int cnt) {
        if (curr == nullptr) {
            return cnt;
        }
        cnt++;
        return max(Helper(curr->left, cnt), Helper(curr->right, cnt));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int cnt = 0;
        if (root == nullptr) return 0;
        cnt = Helper(root->left, cnt) + Helper(root->right, cnt);
        return cnt;
    }
};
