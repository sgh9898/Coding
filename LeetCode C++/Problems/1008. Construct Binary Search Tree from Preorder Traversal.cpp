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
    TreeNode *BuildTree(vector<int>& preorder, int& pos, int min, int max) {
        if (pos >= preorder.size()) return nullptr;
        int val = preorder[pos];
        if (val < min || val > max) return nullptr;
        pos++;
        TreeNode *node = new TreeNode(val);
        node->left = BuildTree(preorder, pos, min, val);
        node->right = BuildTree(preorder, pos, val, max);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int pos = 0;
        return BuildTree(preorder, pos, INT_MIN, INT_MAX);
    }
};
