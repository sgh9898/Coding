/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool CheckSymmetric(TreeNode *lt, TreeNode *rt) {
        if (lt == nullptr && rt == nullptr) {
            return true;
        } else if (lt && rt && lt->val == rt->val) {
            return (CheckSymmetric(lt->left,rt->right) && CheckSymmetric(lt->right,rt->left));
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