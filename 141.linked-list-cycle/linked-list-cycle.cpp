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
        if(!head) return false;
        ListNode* p = head;
        ListNode* q = head;
        while(p && q->next)
        {
            if(!q->next->next) break;
            q = q->next->next;
            p = p->next;
            if(p == q) return true;
        }
        return false;
    }
};