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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* res=new ListNode(0);
        res->next=head;
        ListNode* pre=res;
        for(int i=0;i<m-1;i++) pre=pre->next;
        ListNode* p=pre->next;
        ListNode* temp;
        for(int i=0;i<n-m;i++)
        {
            temp=p->next;
            p->next=temp->next;
            temp->next=pre->next;
            pre->next=temp;
            
        }
        
        return res->next;
    }
};