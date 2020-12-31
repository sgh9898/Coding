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
    TreeNode *ConvertTree(vector<int>& vec_in, int lt, int rt) {
        if (lt > rt) {
            return nullptr;
        } else {
            int mid = (lt+rt+1)/2;
            TreeNode *cur_node = new TreeNode(vec_in[mid]);
            cur_node->left = ConvertTree(vec_in,lt,mid-1);
            cur_node->right = ConvertTree(vec_in,mid+1,rt);
            return cur_node;
        }
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return ConvertTree(nums,0,nums.size()-1);
    }
};
