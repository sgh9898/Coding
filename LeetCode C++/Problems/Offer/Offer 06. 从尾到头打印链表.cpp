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
    vector<int> reversePrint(ListNode* head) {
    	vector<int> vec;

    	while (head) {
    		vec.push_back(head->val);
    		head = head->next;
    	}

    	reverse(vec.begin(), vec.end());
    	return vec;
    }
};