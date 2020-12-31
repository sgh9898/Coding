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
    void TreeToVec(TreeNode *node, vector<int>& vec_val) {
        if (!node)  return;
        TreeToVec(node->left, vec_val);
        vec_val.push_back(node->val);
        TreeToVec(node->right, vec_val);
    }

    vector<int> Merge(vector<int>& vec1, vector<int>& vec2) {
        vector<int> ans;
        int i = 0, j = 0;
        while (i < vec1.size() || j < vec2.size()) {
            if (i < vec1.size() && (j >= vec2.size() || vec1[i] <= vec2[j])) {
                ans.push_back(vec1[i++]);
            } else {
                ans.push_back(vec2[j++]);
            }
        }
        return ans;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1, vec2;
        TreeToVec(root1, vec1);
        TreeToVec(root2, vec2);
        return Merge(vec1, vec2);
    }
};
