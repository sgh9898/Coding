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
    bool CheckNode(TreeNode *target, TreeNode *res) {
        if (!target && !res)    return true;
        if (target && res && target->val == res->val) {
            return CheckNode(target->left,res->left) && CheckNode(target->right,res->right);
        } else {
            return false;
        }
    }

    void FindNode(TreeNode *cloned, TreeNode *target, TreeNode **ptr_res) {
        if (cloned == nullptr)  return;
        if (cloned->val == target->val && CheckNode(target,cloned)) {
            *ptr_res = cloned;
            return;
        } else {
            FindNode(cloned->left,target,ptr_res);
            FindNode(cloned->right,target,ptr_res);
        }
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode *res = cloned;
        FindNode(cloned,target,&res);
        return res;
    }
};
