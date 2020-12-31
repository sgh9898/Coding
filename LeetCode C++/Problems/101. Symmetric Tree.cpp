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
    bool CheckSymmetric(TreeNode *lt, TreeNode *rt) {
        if (lt == nullptr && rt == nullptr) {
            return true;
        } else if (lf && rt && lt->val == rt->val) {
            return (CheckSymmetric(lf->left,rt->right) && CheckSymmetric(lf->right,rt->left));
        } else {
            return false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        } else {
            return CheckSymmetric(root->left,root->right);
        }
    }
};
