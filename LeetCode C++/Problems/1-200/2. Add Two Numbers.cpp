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
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* head = l1;

         // standard
         while (l1->next && l2->next ) {
             l1->val += l2->val;
             if (l1->val >= 10) {
                 l1->val -= 10;
                 l1->next->val += 1;
             }
             l1 = l1->next;
             l2 = l2->next;
         }

         // l1 ends
         if (l2->next) {
             l1->next = l2->next;
         }

         // l2 ends
         l1->val += l2->val;
         delete(l2);

         // check
         while (l1 && l1->val >= 10) {
             if (l1->next) {
                 l1->val -= 10;
                 l1->next->val += 1;
             } else {
                 l1->val -= 10;
                 l1->next = new ListNode(1);
             }
             l1 = l1->next;
         }

         return head;
     }
 };
