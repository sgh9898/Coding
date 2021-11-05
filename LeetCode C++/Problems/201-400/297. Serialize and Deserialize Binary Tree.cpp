/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void serial(TreeNode *curr_node, stringstream &str_out) {
        if(curr_node) {
            str_out << curr_node->val << " ";
            serial(curr_node->left,str_out);
            serial(curr_node->right,str_out);
        } else {
            str_out << "! ";
        }
    }

    TreeNode *deserial(stringstream &str_in) {
        string temp;
        str_in >> temp;
        if (temp == "!") {
            return NULL;
        } else {
            TreeNode *new_node = new TreeNode(stoi(temp));
            new_node->left = deserial(str_in);
            new_node->right = deserial(str_in);
            return new_node;
        }
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream str_out;
        serial(root,str_out);
        return str_out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream str_in(data);
        return deserial(str_in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
