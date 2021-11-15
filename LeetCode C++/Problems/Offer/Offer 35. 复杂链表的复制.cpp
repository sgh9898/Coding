/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if (head == nullptr)
            return head;

        unordered_map<Node*, Node*> map;

        Node* cur = head;
        while (cur)
        {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur)
        {
            Node* node = map[cur];
            node->next = map[cur->next];
            node->random = map[cur->random];
            cur = cur->next;
        }

        return map[head];
    }
};
