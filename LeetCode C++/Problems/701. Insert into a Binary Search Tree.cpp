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
    void Helper(TreeNode* parent, TreeNode* curr, int val) {
        if (curr == nullptr) {
            TreeNode* temp = new TreeNode(val);
            if (val < parent->val) {
                parent->left = temp;
            } else {
                parent->right = temp;
            }
            return;
        }
        if (val < curr->val) {
            Helper(curr, curr->left, val);
        } else {
            Helper(curr, curr->right, val);
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        Helper(nullptr, root, val);
        return root;
    }
};
