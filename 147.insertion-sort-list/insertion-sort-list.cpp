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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *res = new ListNode(INT_MIN);
        while(head)
        {
            ListNode *p = new ListNode(head->val);
            ListNode *q = res;
            while(q)
            {
                if(!q->next) 
                {
                    q->next = p;
                    break;
                }
                else if(q->val <= p->val && p->val <= q->next->val)
                {
                    p->next = q->next;
                    q->next = p;
                    break;
                }
                q = q->next;
            }
            head = head->next;
        }
        return res->next;
    }
};