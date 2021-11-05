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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_set<TreeNode*> ancestor;
        TreeNode* curr = root;
        // ancestors of p, including p
        while (curr != p) {
            ancestor.insert(curr);
            if (p->val < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        ancestor.insert(p);

        // find lowest common ancestor
        TreeNode* res = nullptr;
        curr = root;
        if (ancestor.count(q)) {
            return q;
        }
        while (curr != q) {
            if (ancestor.count(curr)) {
                res = curr;
            }
            if (q->val < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return res;
    }
};
