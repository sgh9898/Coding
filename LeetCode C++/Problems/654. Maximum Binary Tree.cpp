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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> vec_node;
        for (auto n : nums) {
            TreeNode *cur_node = new TreeNode(n);   // new node
            while (!vec_node.empty() && n > vec_node.back()->val) {
                cur_node->left = vec_node.back();    // local max
                vec_node.pop_back();
            }
            if (!vec_node.empty()) {
                vec_node.back()->right = cur_node;
            }
            vec_node.push_back(cur_node);
        }
        return vec_node.front();
    }
};
