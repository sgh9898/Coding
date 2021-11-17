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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
    	if (B == nullptr) {
    		return false;
    	}
    	return traverse(A, B);
    }

    bool traverse(TreeNode* A, TreeNode* B) {
    	// terminate
    	if (A == nullptr) {
    		return false;
    	// matches
    	} else {
    		return check(A, B) || traverse(A->left, B) || traverse(A->right, B);
    	}
    }

    bool check(TreeNode* A, TreeNode* B) {
    	// terminate
    	if (B == nullptr) {
    		return true;
    	} else if (A == nullptr || A->val != B->val) {
    		return false;
		// matches
    	} else {
    		return check(A->left, B->left) && check(A->right, B->right);
        }
    }
};