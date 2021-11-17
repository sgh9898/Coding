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
    vector<int> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> process;
        vector<int> res;
        process.push(root);
        while (!process.empty()) {
            TreeNode* curr = process.front();
            process.pop();
            res.push_back(curr->val);
            if (curr->left != nullptr) {
                process.push(curr->left);
            }
            if (curr->right != nullptr) {
                process.push(curr->right);
            }
        }
        return res;
    }
};