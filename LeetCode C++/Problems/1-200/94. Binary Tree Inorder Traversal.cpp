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
    void Inorder(TreeNode *node, vector<int>& vec) {
        if (!node)  return;
        Inorder(node->left,vec);
        vec.push_back(node->val);
        Inorder(node->right,vec);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        Inorder(root,vec);
        return vec;
    }
};
