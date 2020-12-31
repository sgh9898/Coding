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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prehead = new ListNode(0);
        prehead->next = head;

        ListNode *prev = prehead, *cur = head, *to_del = nullptr;
        while (cur) {
            if (cur->val == val) {
                prev->next = cur->next;
                to_del = cur;
            } else {
                prev = prev->next;
            }
            cur = cur->next;

            // delete
            if (to_del) {
                delete to_del;
                to_del = nullptr;
            }
        }

        ListNode *res = prehead->next;
        delete prehead;
        return res;
    }
};
