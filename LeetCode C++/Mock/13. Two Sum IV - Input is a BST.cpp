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
    bool Helper(TreeNode* cur_node, int k, unordered_set<int>& ans) {
        if (cur_node == nullptr)  return false;
        auto iter = ans.find(cur_node->val);
        if (iter != ans.end()) {
            return true;
        } else {
            ans.insert(k - cur_node->val);
            return Helper(cur_node->left, k, ans) || Helper(cur_node->right, k, ans);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> ans;
        return Helper(root, k, ans);
    }
};
