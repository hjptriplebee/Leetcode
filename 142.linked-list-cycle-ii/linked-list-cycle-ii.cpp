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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode* p = head;
        ListNode* q = head;
        while(p && q->next)
        {
            if(!q->next->next) return NULL;
            p = p->next;
            q = q->next->next;
            if(p == q) break;
        }
        if(!q->next) return NULL;
        q = head;
        while(p != q)
        {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};