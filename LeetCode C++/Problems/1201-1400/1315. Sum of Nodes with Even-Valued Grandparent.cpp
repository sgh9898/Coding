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
    int SumOfChildren(TreeNode *cur_node, TreeNode *parent, TreeNode *grandparent) {
        if (!cur_node)    return 0;
        int sum = 0;
        if (grandparent && grandparent->val % 2 == 0)    sum += cur_node->val;
        sum += SumOfChildren(cur_node->left,cur_node,parent);
        sum += SumOfChildren(cur_node->right,cur_node,parent);
        return sum;
    }

    int sumEvenGrandparent(TreeNode* root) {
        return SumOfChildren(root,nullptr,nullptr);
    }
};
