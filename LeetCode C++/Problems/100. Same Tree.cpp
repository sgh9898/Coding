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
    bool CheckTwoTrees(TreeNode *lt,TreeNode *rt) {
        if (lt == nullptr && rt == nullptr) {
            return true;
        } else if (lt && rt && lt->val == rt->val) {
            return CheckTwoTrees(lt->left,rt->left) && CheckTwoTrees(lt->right,rt->right);
        }
        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return CheckTwoTrees(p,q);
    }
};
