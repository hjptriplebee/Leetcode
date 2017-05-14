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
        ListNode* result=new ListNode(0);
        ListNode* pre=result;
        pre->next=head;
        while(head && head->next)
        {
            if(head->val!=head->next->val)
                pre=pre->next;
            else
            {
                while(head->next!=NULL)
                {
                    if(head->val!=head->next->val) break;
                    head=head->next;
                }
                pre->next=head->next;
            }
            head=head->next;
        }
        return result->next;
    }
};