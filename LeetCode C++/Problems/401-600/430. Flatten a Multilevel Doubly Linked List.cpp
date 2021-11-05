/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        stack<Node*> stk;
        Node* dummy_head = new Node(0);
        dummy_head->next = head;

        // break down
        while (dummy_head) {
            // child
            if (dummy_head->child != nullptr) {
                if (dummy_head->next != nullptr) stk.push(dummy_head->next);
                dummy_head->next = dummy_head->child;
                dummy_head->child->prev = dummy_head;
                dummy_head->child = nullptr;
            }
            if (dummy_head->next == nullptr) break;
            dummy_head = dummy_head->next;
        }

        // Merge
        while(!stk.empty()) {
            dummy_head->next = stk.top();
            stk.top()->prev = dummy_head;
            stk.pop();
            while (dummy_head->next) {
                dummy_head = dummy_head->next;
            }
        }
        return head;
    }
};
