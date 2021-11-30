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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // no need to modify
        if (head == nullptr || k <= 1) {
            return head;
        }
        // find the new head
        ListNode* ans = head;
        for (int i = k; i > 1; i--) {
            ans = ans->next;
            if (ans == nullptr) {
                return head;
            }
        }
        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        ListNode* tail = prehead->next;
        int len = k;
        while (true) {
            // reach the end of the list
            if (tail == nullptr) {
                    break;
            }

            // extend rightend
            if (len > 1) {
                len--;
                tail = tail->next;
            } else if (len == 1) {
                // next round
                prehead = ReverseList(prehead, tail);
                tail = prehead->next;
                len = k;
            } 
        }
        return ans;
    }

    ListNode* ReverseList(ListNode* prehead, ListNode* tail) {
        // store the prehead/tail for the next round
        ListNode* next_prehead = prehead->next;
        ListNode* next_tail = tail->next;

        // prehead-->post-->curr-->...
        ListNode* post = prehead->next;
        ListNode* curr = post->next;
        // swap curr and post recursively
        while (true) {
            ListNode* next_curr = curr->next;
            curr->next = post;
            // end if curr is the last element
            if (curr == tail) {
                break;
            }
            post = curr;
            curr = next_curr;
        }
        // link prehead-->curr-->post-->...-->next_prehead-->next_tail
        next_prehead->next = next_tail;
        prehead->next = curr;
        return next_prehead;
    }
};