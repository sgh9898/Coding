/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void helper(ListNode* pre_node) {
        ListNode* node1 = pre_node->next;
        if (!node1)  return;
        ListNode* node2 = pre_node->next->next;
        if (!node2)  return;

        pre_node->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        helper(node1);
    }

    ListNode* swapPairs(ListNode* head) {
        if (!head)  return nullptr;
        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        helper(prehead);
        return prehead->next;
    }
};
