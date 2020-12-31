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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre_node = new ListNode(0);
        pre_node->next = head;
        ListNode* first = head;
        ListNode* second = pre_node;

        for (int i = 0; i < n; i++) {
            first = first->next;
        }

        while (first) {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;
        ListNode* ans = pre_node->next;
        delete pre_node;
        return ans;
    }
};
