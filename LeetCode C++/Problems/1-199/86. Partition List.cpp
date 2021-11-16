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
    ListNode* partition(ListNode* head, int x) {
        ListNode* before_head = new ListNode(0);
        ListNode* after_head = new ListNode(0);
        ListNode* before = before_head;
        ListNode* after = after_head;

        // split
        while (head) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else if (head->val >= x) {
                after->next = head;
                after = after->next;
            }

            head = head->next;
        }

        //combination
        after->next = NULL;
        before->next = after_head->next;

        return before_head->next;
    }

};
