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
    void helper(TreeNode* curr, int lvl, int pos, vector<pair<int, int>>& width) {
        if (curr == nullptr) return;

        // reaching a new level
        if (lvl == width.size()) {
            width.push_back(make_pair(pos, pos));
            // updating left and right endpoint
        } else {
            width[lvl].first = min(pos, width[lvl].first);
            width[lvl].second = max(pos, width[lvl].second);
        }

        helper(curr->left, lvl + 1, pos * 2, width);
        helper(curr->right, lvl + 1, pos * 2 + 1, width);
    }

    int widthOfBinaryTree(TreeNode* root) {
        vector<pair<int, int>> width;
        helper(root, 0, 0, width);
        int res = 0;
        for (auto iter = width.begin(); iter != width.end(); iter++) {
            res = max(res, iter->second - iter->first);
        }
        return res;
    }
};
