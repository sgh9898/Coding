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
    TreeNode *prev, *f, *s;

    void Inorder(TreeNode *cur_node) {
        if (cur_node == nullptr) return;
        Inorder(cur_node->left);
        if (!f && prev && prev->val >= cur_node->val) {     // first
            f = prev;
        }
        if (f && prev && prev->val >= cur_node->val) {      // second
            s = cur_node;
        }
        prev = cur_node;
        Inorder(cur_node->right);
    }

    void recoverTree(TreeNode* root) {
        if (!root) return;
        Inorder(root,vec_val);
        swap(f->val,s->val);
    }
}
