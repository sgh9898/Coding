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
    void helper(TreeNode* curr, int check, int& cnt) {
        if (curr == nullptr)  return;
        check = (1<<curr->val) ^ check;
        if (curr->left == nullptr && curr->right == nullptr) {
            if (_buildin_popcount(check) < 2) {
                cnt++;
            }
            return;
        }
        helper(curr->left, check, cnt);
        helper(curr->right, check, cnt);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt = 0;
        helper(root, 0, cnt);
        return cnt;
    }
};
