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
    vector<TreeNode*> GenerateBSTs(int start, int end) {
        if (start > end)    return {nullptr};
        vector<TreeNode*> tree;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left_trees = GenerateBSTs(start, i-1);
            vector<TreeNode*> right_trees = GenerateBSTs(i+1, end);

            for (auto& left : left_trees) {
                for (auto& right : right_trees) {
                    TreeNode* node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    tree.emplace_back(node);
                }
            }
        }
        return tree;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return GenerateBSTs(1, n);
    }
};
