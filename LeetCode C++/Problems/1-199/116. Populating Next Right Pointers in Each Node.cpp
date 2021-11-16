/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void DifferentParent(Node* start, Node* end) {
        if (start == nullptr || end == nullptr) return;
        start->next = end;
        DifferentParent(start->right, end->left);
    }

    void SameParent(Node* lt, Node* rt) {
        if (lt == nullptr || rt == nullptr) return;
        lt->next = rt;
        SameParent(lt->left, lt->right);
        SameParent(rt->left, rt->right);
        DifferentParent(lt->right, rt->left);
    }

    Node* connect(Node* root) {
        if (root == nullptr)    return nullptr;
        SameParent(root->left, root->right);
        return root;
    }
};
