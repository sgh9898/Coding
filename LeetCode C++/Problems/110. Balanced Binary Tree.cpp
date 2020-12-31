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
    int Height(TreeNode *cur_node) {
        if (cur_node == nullptr) {      // no child
            return 0;
        }
        int hgt_lt = Height(cur_node->left);
        int hgt_rt = Height(cur_node->right);
        if (hgt_lt == -1 || hgt_rt == -1 || abs(hgt_lt-hgt_rt) >1) {
            return -1;
        } else {
            return max(hgt_lt,hgt_rt) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return Height(root) >= 0;
    }
};
