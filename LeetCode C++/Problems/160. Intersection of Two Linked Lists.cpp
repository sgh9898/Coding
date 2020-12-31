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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* h1=headA;
        ListNode* h2=headB;
        int c1=0,c2=0,d=0;
        while(h1!=NULL)
        {
            c1++;
            h1=h1->next;
        }
        while(h2!=NULL)
        {
            c2++;
            h2=h2->next;
        }
        d=abs(c1-c2);
        if(c1>=c2)
        {
            while(d--)
            {
                headA=headA->next;
            }
        }
        else
        {
            while(d--)
            {
                headB=headB->next;
            }
        }
        while(headB!=NULL && headA!=NULL && headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};
