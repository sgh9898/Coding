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
    void CalSum(TreeNode *cur_node, vector<int>& sum_vec, int dep) {
        if (!cur_node)  return;
        if (dep >= sum_vec.size())  {       // new level
            sum_vec.push_back(cur_node->val);
        } else {
            sum_vec[dep] += cur_node->val;  // existing level
        }
        CalSum(cur_node->left,sum_vec,dep+1);
        CalSum(cur_node->right,sum_vec,dep+1);
    }

    int deepestLeavesSum(TreeNode* root) {
        if (!root)  return 0;
        vector<int> sum_vec;
        CalSum(root,sum_vec,0);
        return sum_vec.back();
    }
};
