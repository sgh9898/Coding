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
    int pre_idx = 0;

    TreeNode* Build(vector<int>& preorder, vector<int>& inorder, int in_start, int in_end) {
        if (pre_idx >= preorder.size()) return nullptr; // end

        // find children
        int in_idx = -1;
        for (int i = in_start; i <= in_end; i++) {
            if (inorder[i] == preorder[pre_idx]) {
                in_idx = i;
                break;
            }
        }
        if (in_idx == -1)   return nullptr;

        TreeNode *new_node = new TreeNode(preorder[pre_idx++]);
        new_node->left = Build(preorder, inorder, in_start, in_idx-1);
        new_node->right = Build(preorder, inorder, in_idx+1, in_end);
        return new_node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return Build(preorder, inorder, 0, inorder.size()-1);
    }
};
