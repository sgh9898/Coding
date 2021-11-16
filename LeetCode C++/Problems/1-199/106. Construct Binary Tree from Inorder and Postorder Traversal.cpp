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
    int post_idx;

    TreeNode* Build(vector<int>& inorder, vector<int>& postorder, int in_start, int in_end) {
        if (post_idx < 0) return nullptr; // end

        // find children
        int in_idx = -1;
        for (int i = in_start; i <= in_end; i++) {
            if (inorder[i] == postorder[post_idx]) {
                in_idx = i;
                break;
            }
        }
        if (in_idx == -1)   return nullptr;

        TreeNode *new_node = new TreeNode(postorder[post_idx--]);
        new_node->right = Build(inorder, postorder, in_idx+1, in_end);
        new_node->left = Build(inorder, postorder, in_start, in_idx-1);
        return new_node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post_idx = postorder.size()-1;
        return Build(inorder, postorder, 0, inorder.size()-1);
    }
};
