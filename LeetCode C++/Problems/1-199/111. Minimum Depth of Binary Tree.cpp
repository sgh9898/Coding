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
    int CalMinDepth(TreeNode* cur_node, int dep) {
        if (!cur_node)  return 0;
        if (!cur_node->left && !cur_node->right)    return dep; // no child
        dep++;
        if (cur_node->left && cur_node->right) {            // two children
            return min(CalMinDepth(cur_node->left,dep),CalMinDepth(cur_node->right,dep));
        } else {        // one child
            return max(CalMinDepth(cur_node->left,dep),CalMinDepth(cur_node->right,dep));
        }
    }

    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        } else {
            return CalMinDepth(root,1);
        }
    }
};
