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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = new ListNode(-1);
        p->next = head;
        ListNode* q = p;
        while(p->next)
        {
            if(p->next->val == val) 
                p->next = p->next->next;
            else
                p = p->next;
        }
        return q->next;
    }
};