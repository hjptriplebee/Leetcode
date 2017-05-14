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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p=head;
        if(!p) return head;
        ListNode* pre=p;
        while(p->next!=NULL)
        {
            p=p->next;
            if(p->val==pre->val)
                pre->next=p->next;
            else
                pre=p;
        }
        return head;
    }
};