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
    void Recursion(TreeNode* curr, int low, int high, int& sum) {
        if (curr == nullptr) {
            return;
        }
        // too small
        if (curr->val < low) {
            Recursion(curr->right, low, high, sum);
        } else if (curr->val > high) {
            Recursion(curr->left, low, high, sum);
        } else {
            sum += curr->val;
            Recursion(curr->left, low, high, sum);
            Recursion(curr->right, low, high, sum);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        Recursion(root, low, high, sum);
        return sum;
    }
};
