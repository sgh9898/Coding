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
     TreeNode* recoverFromPreorder(string S) {
         if (S.empty()) return nullptr;
         int pos = 0;
         return decode(S, pos, 0);
     }

 private:
     TreeNode *decode(const std::string &s, int &pos, int dashCount) {
         if (pos >= s.size()) return nullptr;
         auto curPos = pos;
         while (curPos < s.size() && s[curPos] == '-') ++curPos;
         if (curPos - pos != dashCount) return nullptr;
         int val = 0;
         for(; curPos < s.size() && s[curPos] != '-'; ++curPos)
             val = val * 10 + s[curPos] - '0';
         auto node = new TreeNode(val);
         pos = curPos;
         node->left = decode(s, pos, dashCount + 1);
         node->right = decode(s, pos, dashCount + 1);
         return node;
     }
 };
