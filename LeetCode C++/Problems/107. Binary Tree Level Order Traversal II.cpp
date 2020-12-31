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
    void Traverse(TreeNode *cur_node,vector<vector<int>>& vec_out,int dep) {
        if (!cur_node)  return;
        if (dep+1 > vec_out.size()) {       // new level
            vec_out.push_back({cur_node->val});
        } else {                            // add new num
            vec_out[dep].push_back(cur_node->val);
        }
        dep++;
        Traverse(cur_node->left,vec_out,dep);
        Traverse(cur_node->right,vec_out,dep);
        return;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vec_out;
        int dep = 0;
        Traverse(root,vec_out,0);
        reverse(vec_out.begin(),vec_out.end());
        return vec_out;
    }
};
