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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* prev = head;
        ListNode* cur = head->next;
        while (prev && prev->next) {
            if (prev->val == cur->val) {
                prev->next = cur->next;
                cur = cur->next;
            } else {
                prev = prev->next;
            }
        }
        return head;
    }
};
