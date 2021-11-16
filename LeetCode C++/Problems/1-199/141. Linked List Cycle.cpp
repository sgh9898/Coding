/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }

    // bool hasCycle(ListNode *head) {
    //     unordered_set<ListNode*> visited;
    //     while (head != nullptr) {
    //         if (visited.count(head)) {
    //             return true;
    //         }
    //         visited.insert(head);
    //         head = head->next;
    //     }
    //     return false;
    // }
};
