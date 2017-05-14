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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small=new ListNode(0);
        ListNode* result=small;
        ListNode* big=new ListNode(0);
        ListNode* result2=big;
        while(head!=NULL)
        {
            if(head->val>=x)
            {
                big->next=head;
                big=big->next;
            }
            else
            {
                
                small->next=head;
                small=small->next;
            }
            head=head->next;
        }
        big->next=NULL;
        small->next=result2->next;
        return result->next;
    }
};