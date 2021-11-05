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
    void Inorder(TreeNode* curr, int& pre, int& diff) {
        if (curr == nullptr || diff == 1) {
            return;
        }
        Inorder(curr->left, pre, diff);
        if (pre == INT_MIN) {
            pre = curr->val;
        } else {
            diff = min(curr->val - pre, diff);
            pre = curr->val;
        }
        Inorder(curr->right, pre, diff);
    }

    int minDiffInBST(TreeNode* root) {
        int pre = INT_MIN, diff = INT_MAX;
        Inorder(root, pre, diff);
        return diff;
    }
};
