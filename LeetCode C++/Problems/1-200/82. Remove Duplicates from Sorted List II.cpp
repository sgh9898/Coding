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
    void DelDuplicates(ListNode* parent, ListNode* curr, ListNode* to_del) {
        if (curr == nullptr) return;
        if (curr->next == nullptr) {
            if (curr == to_del) {
                delete curr;
                curr = nullptr;
                parent->next = nullptr;
            }
            return;
        }

        // no nullptr
        if (curr->val == curr->next->val) {  // duplicates
            to_del = curr->next;
            parent->next = curr->next;
            delete curr;
            curr = nullptr;
            DelDuplicates(parent, parent->next, to_del);
        } else {  // no duplicates
            if (curr == to_del) {
                parent->next = curr->next;
                delete curr;
                curr = nullptr;
                DelDuplicates(parent, parent->next, nullptr);
            } else {
                DelDuplicates(curr, curr->next, nullptr);
            }
        }
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy_head = new ListNode(-1);
        dummy_head->next = head;
        DelDuplicates(dummy_head, head, nullptr);
        return dummy_head->next;
    }
};
