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
    int sum = INT_MIN;

    int PostorderMax(TreeNode* node) {
        if (node == nullptr)    return 0;

        int lt_sum = max(PostorderMax(node->left), 0);
        int rt_sum = max(PostorderMax(node->right), 0);

        int local_max = node->val + lt_sum + rt_sum;

        sum = max(sum, local_max);

        return node->val + max(lt_sum, rt_sum);
    }

    int maxPathSum(TreeNode* root) {
        PostorderMax(root);
        return sum;
    }
};
