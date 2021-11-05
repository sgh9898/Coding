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
    int AddNodes(TreeNode* cur_node, int sum) {
        if (cur_node == nullptr) {
            return 0;
        } else if (cur_node->left == nullptr && cur_node->right == nullptr) {
            return sum * 10 + cur_node->val;
        } else {
            sum = sum * 10 + cur_node->val;
            return AddNodes(cur_node->left, sum) + AddNodes(cur_node->right, sum);
        }
    }

    int sumNumbers(TreeNode* root) {
        return AddNodes(root, 0);
    }
};
