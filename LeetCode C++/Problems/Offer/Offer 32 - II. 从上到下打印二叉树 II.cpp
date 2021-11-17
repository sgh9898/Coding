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
    void Helper(TreeNode* node, vector<vector<int>>& vec, int depth) {
        if (!node)  return;
        if (depth >= vec.size()) {
            vec.push_back(vector<int>());
        }
        vec[depth].push_back(node->val);
        Helper(node->left, vec, depth+1);
        Helper(node->right, vec, depth+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        Helper(root, vec, 0);
        return vec;
    }
};