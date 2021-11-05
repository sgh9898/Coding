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
    bool CheckSum(TreeNode* cur_node, int val, int sum) {
        if (cur_node == nullptr)    return false;
        val += cur_node->val;
        if (!cur_node->left && !cur_node->right)    return val == sum;
        return CheckSum(cur_node->left,val,sum) || CheckSum(cur_node->right,val,sum);
    }

    bool hasPathSum(TreeNode* root, int sum) {
        return CheckSum(root,0,sum);
    }
};
