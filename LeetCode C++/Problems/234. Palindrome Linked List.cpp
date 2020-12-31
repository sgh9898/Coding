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
    bool isPalindrome(ListNode* head) {
        if (!head)  return true;

        ListNode *slow, *fast, *mid;
        slow = head;
        fast = head;
        // split up
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast != nullptr) {
            mid = slow->next;       // odd
        } else {
            mid = slow;             // even
        }

        // reverse
        ListNode *pre, *temp;
        pre = nullptr;
        while (mid) {
            temp = mid->next;
            mid->next = pre;
            pre = mid;
            mid = temp;
        }                           // head2 = pre

        while (pre != nullptr) {
            if (pre->val != head->val) {
                return false;
            } else {
                pre = pre->next;
                head = head->next;
            }
        }
        return true;
    }
};
