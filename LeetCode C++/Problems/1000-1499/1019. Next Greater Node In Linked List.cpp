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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<pair<int,int>> node_stack;
        int idx = 0;

        while (head)
        {
            res.push_back(0);           // starts from 0
            while (!node_stack.empty() && head->val > node_stack.top().first) {    // found
                res[node_stack.top().second] = head->val;
                node_stack.pop();
            }
            node_stack.push(make_pair(head->val,idx));      // (val,idx)
            head = head->next;
            idx++;
        }
        return res;
    }
};
